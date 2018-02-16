/*
* CrashingTest
* Christian Miranda Espinoza
* A01223255
* chrisme1320
* Tests Crashing.c methods
*/
#include "utest.h"
#include "../src/Crashing.h"
#include <stdio.h>

static char * test_turnRight()
{
	char a='N';
	turnRight(&a);
	assert_test("a must be E",a=='E');
	turnRight(&a);
	assert_test("a must be S",a=='S');
	turnRight(&a);
	assert_test("a must be W",a=='W');
	turnRight(&a);
	assert_test("a must be N",a=='N');
	return 0;
}
static char * test_turnLeft()
{
	char a='N';
	turnLeft(&a);
	assert_test("a must be W",a=='W');
	turnLeft(&a);
	assert_test("a must be S",a=='S');
	turnLeft(&a);
	assert_test("a must be E",a=='E');
	turnLeft(&a);
	assert_test("a must be N",a=='N');
	return 0;
}
static char * test_makeWarehouse()
{
	int xLength=3,
	yLength=3,
	errors=0,
	i=0,
	j=0;
	char **Robots=makeWarehouse(xLength,yLength);
	for (i = 0; i < xLength; i++)
	{
		for (j = 0; j < yLength; j++)
		{
			if(Robots[i][j]!=' '){
				errors++;
			}	
		}
	}
	assert_test("warehouse must be empty", errors==0);
	return 0;
}
static char * test_positionRobot()
{
	int xLength=3,yLength=3;
	char **Robots=makeWarehouse(xLength,yLength);
	positionRobot(Robots,0,0,'S');
	assert_test("Robot was not positioned correctly", Robots[0][0]=='S');
	return 0;
}
static char * test_moveForward()
{
	int i=0,j=0;
	char **Robots=makeWarehouse(3,3);
	positionRobot(Robots,i,j,'S');
	moveForward(Robots,3,3,&i,&j);
	assert_test("Robot didn't move correctly",Robots[0][0]==' ' && Robots[1][0]=='S' && i==1 && j==0);
	turnLeft(&Robots[1][0]);
	moveForward(Robots,3,3,&i,&j);
	assert_test("Robot didn't move correctly",Robots[1][0]==' ' && Robots[1][1]=='E' && i==1 && j==1);
	turnLeft(&Robots[1][1]);
	moveForward(Robots,3,3,&i,&j);
	assert_test("Robot didn't move correctly",Robots[1][1]==' ' && Robots[0][1]=='N' && i==0 && j==1);
	turnLeft(&Robots[0][1]);
	moveForward(Robots,3,3,&i,&j);
	assert_test("Robot didn't move correctly",Robots[0][1]==' ' && Robots[0][0]=='W' && i==0 && j==0);
	return 0;
}
static char * test_checkCrashRobot()
{
	int Robots[3][2]={1,2,0,0,1,2};
	int index=0;
	index=checkCrashRobot(0,Robots,3);
	assert_test("Wrong crash",index==2);
	return 0;
}
int main()
{
	run_test("Test turn right: ",test_turnRight);
	run_test("Test turn left: ",test_turnLeft);
	run_test("Test make Warehouse: ",test_makeWarehouse);
	run_test("Test position robot: ",test_positionRobot);
	run_test("Test move forward: ",test_moveForward);
	run_test("Test check crash: ",test_checkCrashRobot);
	return 0;
}