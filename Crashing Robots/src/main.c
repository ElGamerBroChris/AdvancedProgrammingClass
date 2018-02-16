/*
* main.c
* Christian Miranda Espinoza
* A01223255
* chrisME1320
*/
#include <stdio.h>
#include <unistd.h>
#include "Crashing.h"
int main(int argc, char **argv)
{	
	int index=2,
	i=0,j=0,k,w,
	crash=0,
	testCases=atoi(argv[1]),
	xLength,
	yLength,
	NoOfRobots,
	NoOfInstructions;
	char **Robots;
	for(k=0;k<testCases;k++)
	{
		xLength=atoi(argv[index]);
		index++;
		yLength=atoi(argv[index]);
		index++;
		NoOfRobots=atoi(argv[index]);
		index++;
		NoOfInstructions=atoi(argv[index]);
		index++;
		Robots=makeWarehouse(xLength,yLength);
		int Positions[NoOfRobots][2];
		for (i = 0; i < NoOfRobots; i++)
		{
			Positions[i][0]=0;
			Positions[i][1]=0;
		}
		for(i=0;i<NoOfRobots;i++)
		{
			Positions[i][0]=atoi(argv[index+1])-1;
			Positions[i][1]=atoi(argv[index])-1;
			positionRobot(Robots,atoi(argv[index+1])-1,atoi(argv[index])-1,*argv[index+2]);
			index+=3;
		}
		for(i=0;i<NoOfInstructions;i++)
		{
			if(*argv[index+1]=='F')
			{	
				for(j=0;j<atoi(argv[index+2]);j++)
				{
					crash=moveForward(Robots,xLength,yLength,&Positions[atoi(argv[index])-1][0],&Positions[atoi(argv[index])-1][1]);
					if(crash==1)
					{
						printf("Robot %d crashed into wall.\n", atoi(argv[index]));
						index+=3*(NoOfInstructions-i);
						break;
					}
					else if(crash==2)
					{
						printf("Robot %d crashed into Robot %d\n",atoi(argv[index]),checkCrashRobot(atoi(argv[index])-1,Positions,NoOfRobots)+1);
						index+=3*(NoOfInstructions-i);
						break;
					}
				}
				if(crash!=0)
					break;
			}
			else if(*argv[index+1]=='R')
			{
				for(j=0;j<atoi(argv[index+2]);j++){
					turnRight(&Robots[Positions[atoi(argv[index]-1)][0]][Positions[atoi(argv[index]-1)][1]]);
				}
			}
			else
			{
				for(j=0;j<atoi(argv[index+2]);j++){
					turnLeft(&Robots[Positions[atoi(argv[index]-1)][0]][Positions[atoi(argv[index]-1)][1]]);
				}
			}
			index+=3;
		}
		if(crash==0)
				printf("OK\n");
		if(index>=argc)
			break;
	}
	
	return 0;
}