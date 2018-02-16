#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define BUFSIZE 8
#define MAXINT 1000
unsigned int buf[BUFSIZE];
sem_t available;
sem_t ready;

unsigned int ptotal;
unsigned ppos;
sem_t ptotal_mutex;
sem_t ppos_mutex;
void * producer(void *id)
{
  unsigned int pos;
  unsigned int value;
  printf("I am the producer\n");
  while(1)
  {
    sem_wait(&ptotal_mutex);
    value=ptotal;
    if(ptotal++ >=MAXINT)
    {
      sem_post(&ptotal_mutex);
      break;
    }
    sem_post(&ptotal_mutex);

    sem_wait(&available);
    sem_wait(&ppos_mutex);
    pos=ppos;
    ppos=(++ppos)%BUFSIZE;
    sem_post(&ppos_mutex);
    buf[pos]=MAXINT-value;
    sem_post(&ready);
  }
  printf("done producing\n");
  return NULL;
}
unsigned int cpos;
unsigned int ctotal;
sem_t cmutex;
sem_t ctotal_mutex;
void * consumer(void *id)
{
  unsigned int pos;
  printf("I am the consumer\n");
  while(1)
  {
    sem_wait(&ctotal_mutex);
    if(ctotal++ >=MAXINT)
    {
      break;
    }
    sem_post(&ctotal_mutex);

    sem_wait(&ready);
    sem_wait(&cmutex);
    pos=cpos;
    cpos=(++cpos)%BUFSIZE;
    sem_post(&cmutex);

    printf("value is %u\n",buf[pos] );
    sem_post(&available);
  }
  sem_post(&ctotal_mutex);
  printf("done consuming\n");
  return NULL;
}

#define NUM_CONSUMERS 4
#define NUM_PRODUCERS 4
#define NUM_THREADS (NUM_PRODUCERS+NUM_CONSUMERS)
int main()
{

  pthread_t threads[NUM_THREADS];
  long unsigned i;
  cpos=0;
  ppos=0;
  sem_init(&available,0,BUFSIZE);
  sem_init(&ready,0,0);
  sem_init(&cmutex,0,1);
  sem_init(&ppos_mutex,0,1);
  ctotal=0;
  ptotal=0;
  sem_init(&ctotal_mutex,0,1);
  sem_init(&ptotal_mutex,0,1);

  for(i=0;i<NUM_PRODUCERS;i++)
  {
    pthread_create(&threads[i],NULL,producer,NULL);
  }
//i continues from NUM_PRODUCERS
  for(;i<NUM_THREADS;i++)
  {
    pthread_create(&threads[i],NULL,consumer,NULL);
  }
  for(i=0;i<NUM_THREADS;i++)
  {
    pthread_join(threads[i],NULL);
  }
  return 0;
}
