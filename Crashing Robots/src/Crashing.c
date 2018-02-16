/*
* Crashing.c
* Christian Miranda Espinoza
* A01223255
* chrisME1320
* Has all the methods needed for main
*/

#include "Crashing.h"
#include <stdio.h>

char ** makeWarehouse(int xLength,int yLength)
{
	int i=0,j=0;
	char **warehouse;

	warehouse=malloc(yLength*sizeof(char *));

	for(i=0;i<xLength;i++)
	    warehouse[i]=malloc(xLength*sizeof(char));
	for(i=0;i<yLength;i++){
		for (j= 0; j < xLength; j++)
		{
			warehouse[i][j]=' ';
		}
	}
	return warehouse;
}
void positionRobot(char **Robots,int i,int j, char orientation)
{
	Robots[i][j]=orientation;
}
void turnRight(char *Direction)
{
	if(*Direction=='N')
		*Direction='E';
	else if(*Direction=='E')
		*Direction='S';
	else if(*Direction=='S')
		*Direction='W';
	else if(*Direction=='W')
		*Direction='N';
}
void turnLeft(char *Direction)
{
	if(*Direction=='N')
		*Direction='W';
	else if(*Direction=='E')
		*Direction='N';
	else if(*Direction=='S')
		*Direction='E';
	else if(*Direction=='W')
		*Direction='S';
}
int moveForward(char **Robots,int yLength, int xLength, int *i, int *j)
{
	int crashed=0;
	if(Robots[*i][*j]=='N')
	{
		if(*i==0)
			crashed=1;
		else if(Robots[*i-1][*j]!=' ')
		{
			*i-=1;
			crashed=2;
		}
		else
		{
			Robots[*i-1][*j]=Robots[*i][*j];
			Robots[*i][*j]=' ';
			*i-=1;
		}
	}
	else if(Robots[*i][*j]=='S')
	{
		if(*i==yLength-1)
			crashed=1;
		else if(Robots[*i+1][*j]!=' ')
		{
			*i+=1;
			crashed=2;
		}
		else
		{
			Robots[*i+1][*j]=Robots[*i][*j];
			Robots[*i][*j]=' ';
			*i+=1;
		}
	}
	else if(Robots[*i][*j]=='E')
	{
		if(*j==xLength-1)
			crashed=1;
		else if(Robots[*i][*j+1]!=' ')
		{
			*j+=1;
			crashed=2;
		}
		else
		{
			Robots[*i][*j+1]=Robots[*i][*j];
			Robots[*i][*j]=' ';
			*j+=1;
		}
	}
	else if(Robots[*i][*j]=='W')
	{
		if(*j==0)
			crashed=1;
		else if(Robots[*i][*j-1]!=' ')
		{
			*j-=1;
			crashed=2;
		}
		else
		{
			Robots[*i][*j-1]=Robots[*i][*j];
			Robots[*i][*j]=' ';
			*j-=1;
		}
	}
	return crashed;
}

int checkCrashRobot(int robotIndex,int Positions[][2],int positionsLength)
{
	int crashedWith;
	for(crashedWith=0;crashedWith<positionsLength;crashedWith++)
	{
		if(crashedWith!=robotIndex)
			if(Positions[crashedWith][0]==Positions[robotIndex][0]&&Positions[crashedWith][1]==Positions[robotIndex][1])
				return crashedWith;
	}
}