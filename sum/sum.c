/*sum
*chrisme1320
*22/08/2016
*suma los numeros que le pasen
*/
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv){
  int i,total;
  for(i=1;i<argc;i++){
  	total+=atoi(argv[i]);
  }
  printf("%d \n",total);
  return 0;
}
