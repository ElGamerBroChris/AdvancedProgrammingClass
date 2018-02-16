/*
* main.c
* Christian Miranda Espinoza
* A01223255
* chrisme1320
* Methods implemented
*/
#include "FlowSim.h"
#include <stdio.h>
#include <string.h>
int main()
{
  int size;
  char Contained[100],Pipes[100];
  scanf("%d", &size);
  scanf(" %[^\n]", Contained);
  scanf(" %[^\n]", Pipes);
  Container syst[size];
  MakeSystem(size,syst,Contained,Pipes);
  Simulate(syst,size);
	return 0;
}
