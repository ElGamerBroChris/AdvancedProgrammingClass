/*
* FlowSim.c
* Christian Miranda Espinoza
* A01223255
* chrisme1320
* Methods implemented
*/
#include <stdio.h>
#include <string.h>
#include "FlowSim.h"

void MakeContainer(Container *container, char name, int contained,int pipe)
{
  container->name=name;
  container->pipe=pipe;
  container->contained=contained;
}
void MakeSystem(int size,Container * syst,char contained[],char pipes[])
{
  int i;
  char c='a';
  for(i=0;i<size;i++)
  {
    syst[i].name=c;
    c++;
  }
  char *n = strtok(contained, " ");
  for(i=0;i<size;i++)
  {
    syst[i].contained = atoi(n);
    n = strtok(NULL, " ");
  }
  n = strtok(pipes, " ");
  for(i=0;i<size-1;i++)
  {
    syst[i].pipe = atoi(n);
    n = strtok(NULL, " ");
  }
  syst[i].pipe = 0;
}
void WaterIn(Container *container,int water)
{
  container->contained+=water;
}
int WaterOut(Container *container)
{
  if(container->contained<=container->pipe)
  {
    int tmp=container->contained;
    container->contained=0;
    return tmp;
  }
  else
  {
    container->contained-=container->pipe;
    return container->pipe;
  }
}
void Flow(Container *containerA,Container *containerB)
{
  int tmp;
  tmp=WaterOut(containerA);
  WaterIn(containerB,tmp);
}
void Simulate(Container syst[],int NContainers)
{
  int i,total=0,t=0,tmp;
  for(i=0;i<NContainers;i++)
  {
    total+=syst[i].contained;
  }
  printf("  t ");
  for(i=0;i<NContainers;i++)
  {
    printf("  %c ", syst[i].name);
  }
  printf("\n");
  for(i=0;i<NContainers+1;i++)
  {
    printf("====");
  }
  printf("\n");
  while(syst[NContainers-1].contained!=total)
  {
    printf("  %d ",t);
    for(i=0;i<NContainers;i++)
    {
      printf("  %d ",syst[i].contained);
    }
    tmp=syst[0].contained;
    for(i=0;i<NContainers-1;i++)
    {
      if(tmp!=0)
      {
        tmp=syst[i+1].contained;
        Flow(&syst[i],&syst[i+1]);
      }
      else
        tmp=syst[i+1].contained;
    }
    t++;
    printf("\n");
  }
  printf("  %d ",t);
  for(i=0;i<NContainers;i++)
  {
    printf("  %d ",syst[i].contained);
  }
  printf("\n");
}
