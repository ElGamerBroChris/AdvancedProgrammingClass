#include <pthread.h>
#include <stdio.h>

void * hello(void * arg)
{
  printf("Hello World, I am %lu \n",(long unsigned)arg);
  return NULL;
}

#define NUM_THREADS 10
int main()
{
  pthread_t threads[NUM_THREADS];
  long unsigned i;
  for (i=0;i<NUM_THREADS;i++)
  {
    pthread_create(&threads[i],NULL,hello,(void *)i);
  }

  return 0;
}
