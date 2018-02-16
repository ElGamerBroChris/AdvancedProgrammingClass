/*
* Crashing.h
* Christian Miranda Espinoza
* A01223255
* chrisME1320
* Defines the methods needed for main
*/
#ifndef _CRASHINGH_
#define _CRASHINGH_

char ** makeWarehouse(int xLength,int yLength);
void turnRight(char *Direction);
void turnLeft(char *Direction);
void positionRobot(char **Robots,int i,int j, char orientation);
int moveForward(char **Robots,int xLength, int yLength, int *i, int *j);
int checkCrashRobot(int robotIndex,int Positions[][2],int positionsLength);

#endif