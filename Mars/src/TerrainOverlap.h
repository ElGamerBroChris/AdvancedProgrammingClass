/*
Christian Miranda Espinoza A01223255
chrisme1320
Functions of TerrianOverlap
*/
typedef struct
{
  int x1;
  int y1;
  int x2;
  int y2;
}Terrain;
//Checks if there's an intersection between the 2 terrains withing the list
int CheckOverlap(Terrain * terrains,int TerrainA,int TerrainB,int second);

//initializes the terrain structure
int InitTerrain(Terrain *terrain,int x1,int y1,int x2,int y2);

//Checks if theree are any overlaps in the whole array of terrains
int CheckProperties(int length);
