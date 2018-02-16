/*
Christian Miranda Espinoza A01223255
chrisme1320
Implementation of functions on TerrainOverlap
*/
#include "TerrainOverlap.h"
#include <stdio.h>

int InitTerrain(Terrain *terrain,int x1,int y1,int x2,int y2)
{
  terrain->x1=x1;
  terrain->y1=y1;
  terrain->x2=x2;
  terrain->y2=y2;
}

int CheckOverlap(Terrain *terrains,int TerrainA,int TerrainB,int second)
{
  if
  (
    (terrains[TerrainA].x1>terrains[TerrainB].x1&&terrains[TerrainA].x1<terrains[TerrainB].x2)
    ||
    (terrains[TerrainA].x1<terrains[TerrainB].x1&&terrains[TerrainA].x1>terrains[TerrainB].x2)
  )
  {
    if
    (
      (terrains[TerrainA].y1>=terrains[TerrainB].y1&&terrains[TerrainA].y1<=terrains[TerrainB].y2)
      ||
      (terrains[TerrainA].y1<=terrains[TerrainB].y1&&terrains[TerrainA].y1>=terrains[TerrainB].y2)
    )
    return 1;
  }
  else if
  (
    (terrains[TerrainA].x2>terrains[TerrainB].x1&&terrains[TerrainA].x2<terrains[TerrainB].x2)
    ||
    (terrains[TerrainA].x2<terrains[TerrainB].x1&&terrains[TerrainA].x2>terrains[TerrainB].x2)
  )
  {
    if
    (
      (terrains[TerrainA].y2>=terrains[TerrainB].y1&&terrains[TerrainA].y2<=terrains[TerrainB].y2)
      ||
      (terrains[TerrainA].y2<=terrains[TerrainB].y1&&terrains[TerrainA].y2>=terrains[TerrainB].y2)
    )
    return 1;
  }
  else if((terrains[TerrainA].x1==terrains[TerrainB].x1
      &&terrains[TerrainA].y1==terrains[TerrainA].y1)
      &&
      (terrains[TerrainA].x2==terrains[TerrainB].x2
      &&terrains[TerrainA].y2==terrains[TerrainA].y2))
    return 1;
  else if(second)
    return CheckOverlap(terrains,TerrainB,TerrainA,0);

  return 0;
}

int CheckProperties(int length)
{
  Terrain terrains[length];
  int i,j,xa,ya,xb,yb;
  scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
  InitTerrain(&terrains[0],xa,ya,xb,yb);
  for(i=1;i<length;i++)
  {
    scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
    InitTerrain(&terrains[i],xa,ya,xb,yb);
  }
  for(i=0;i<length;i++)
    for(j=i+1;j<length;j++)
    {
      if(CheckOverlap(terrains,i,j,1))
        return 1;
    }
  return 0;
}
