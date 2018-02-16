/*
* FlowSim.h
* Christian Miranda Espinoza
* A01223255
* chrisme1320
* List of all methods in FlowSim
*/

typedef struct {
  char name;
  int pipe;
  int contained;
} Container;
/*
Defines the values of the container
*/
void MakeContainer(Container *container, char name, int contained,int pipe);

/*
Makes the whole system of containers
*/
void MakeSystem(int size,Container * syst,char contained[],char pipes[]);
/*
Sums water into the container
*/
void WaterIn(Container *container,int water);

/*
Returns the amount of water that left container
and updates the container's contained value
*/
int WaterOut(Container *container);

/*
Moves water from contaainer A to container B
*/
void Flow(Container *containerA,Container *containerB);

/*

*/
void Simulate();
