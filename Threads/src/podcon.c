#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define BUFSIZE 10
#define MAXINT 1000
unsigned int buf[BUFSIZE];
sem_t available;
sem_t ready;

unsigned int ptotal;
unsigned ppos;
void * producer(void *id)
{
  unsigned int value = MAXINT;
  unsigned int pos;
  printf("I am the producer\n");
  while(value>0)
  {
    sem_wait(&available);
    buf[pos]=value;
    sem_post(&ready);
    pos=(++pos)%BUFSIZE;
    value--;
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

#define NUM_THREADS 5
#define NUM_CONSUMERS 4
int main()
{

  pthread_t threads[NUM_THREADS];
  long unsigned i;
  cpos=0;
  sem_init(&available,0,BUFSIZE);
  sem_init(&ready,0,0);
  sem_init(&cmutex,0,1);
  ctotal=0;
  sem_init(&ctotal_mutex,0,1);

  pthread_create(&threads[0],NULL,producer,NULL);
  for(i=1;i<=NUM_CONSUMERS;i++)
  {
    pthread_create(&threads[i],NULL,consumer,NULL);
  }
  for(i=0;i<NUM_THREADS;i++)
  {
    pthread_join(threads[i],NULL);
  }
  return 0;
}
