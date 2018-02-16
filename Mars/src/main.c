/*
Christian Miranda Espinoza A01223255
chrisme1320
Interacts with user to give the asked results
*/
#include <stdio.h>
#include "TerrainOverlap.h"

int main()
{
  int cases,terrains,i;
  scanf("%d",&cases);
  int results[cases];
  for(i=0;i<cases;i++)
  {
    scanf("%d",&terrains);
    results[i]=CheckProperties(terrains);
  }
  for(i=0;i<cases;i++)
  {
    if(results[i])
      printf("Difficult problem(s)\n");
    else
      printf("No problems\n");
  }
  return 0;
}
