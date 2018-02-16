/*
Christian Miranda Espinoza A01223255
chrisme1320
Unit testing of TerrianOverlap
*/
#include "utest.h"
#include "../src/TerrainOverlap.h"
#include <stdio.h>
Terrain terrains[4];
static char * test_InitTerrain()
{
	int i;
	for(i=0;i<4;i++)
	{
		InitTerrain(&terrains[i],0,0,2,2);
	}
	assert_test("Terrains Overlap ",terrains[0].x1==0&&
																	terrains[0].y1==0&&
																	terrains[0].x2==2&&
																	terrains[0].y2==2);
	return 0;
}
static char * test_CheckOverlap(){
	//function testing
	int result;
	InitTerrain(&terrains[1],1,1,2,2);
	result=CheckOverlap(terrains,0,1,1);
	assert_test("Terrains Overlap ",result==1);
	return 0;
}

int main(){
	run_test("Test InitTerrain:", test_InitTerrain);
	run_test("Test CheckOverlap:", test_CheckOverlap);
	return 0;
}
