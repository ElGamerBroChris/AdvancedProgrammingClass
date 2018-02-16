/*
* FlowTest.c
* Christian Miranda Espinoza
* A01223255
* chrisme1320
* Tests FlowSim.c methods
*/
#include "utest.h"
#include "../src/FlowSim.h"
#include <stdio.h>

Container syst[3];

static char * TestMakeContainer()
{
	MakeContainer(&syst[0],'a',0,5);
	MakeContainer(&syst[1],'b',0,4);
	MakeContainer(&syst[2],'c',0,0);
	assert_test("Not made correctly",
								syst[0].name=='a' &&
								syst[0].contained==0 &&
								syst[0].pipe==5
							);
	return 0;
}
static char * TestWaterIn()
{
	WaterIn(&syst[0],6);
	assert_test("Was it a leak?", syst[0].contained==6);
	return 0;
}
static char * TestWaterOut()
{
	int water;
	water=WaterOut(&syst[0]);
	assert_test("Not the right amount", syst[0].contained==1&&water==5);
	water=WaterOut(&syst[0]);
	assert_test("Not the right amount either", syst[0].contained==0&&water==1);
	return 0;
}
static char * TestFlow()
{
	MakeContainer(&syst[0],'a',5,5);
	Flow(&syst[1],&syst[0]);
	assert_test("No flow bro",syst[0].contained==5&&syst[1].contained==0);
	return 0;
}
int main()
{
	run_test("Test MakeContainer: ",TestMakeContainer);
	run_test("Test WaterIn: ",TestWaterIn);
	run_test("Test WaterOut: ",TestWaterOut);
	run_test("Test Flow:    ",TestFlow);
	/*
	MakeContainer(&syst[0],'a',11,5);
	MakeContainer(&syst[1],'b',0,4);
	MakeContainer(&syst[2],'c',0,0);
	char string[]={'1','1',' ','0',' ','0'};
	char string2[]={'5',' ','4'};
	MakeSystem(3,&syst,string,string2);
	Simulate(syst,3);
	*/
	return 0;
}
