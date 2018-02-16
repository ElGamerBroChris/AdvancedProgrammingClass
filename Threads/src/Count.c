#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

long unsigned account;
sem_t mutex;
void * add(void * arg)
{
  sem_wait(&mutex);
  account+=1;
  sem_post(&mutex);
  return NULL;
}
#define NUM_THREADS 20000
int main()
{
  pthread_t threads[NUM_THREADS];
  long unsigned i;
  account=0;
  sem_init(&mutex,0,1);
  for (i=0;i<NUM_THREADS;i++)
  {
    pthread_create(&threads[i],NULL,add,(void *)i);
  }
  for (i=0;i<NUM_THREADS;i++)
  {
    pthread_join(threads[i],NULL);
  }
  printf("total %lu\n",account);
  return 0;
}
