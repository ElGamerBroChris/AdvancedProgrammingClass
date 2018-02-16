/*holamundo
*chrisme1320
*22/08/2016
*Dice hola a cada nombre que le pases en la linea de comando
*/
#include <stdio.h>

int main (int argc, char **argv){
  int i;
  for(i=1;i<argc;i++){
    printf("Hola %s \n",argv[i]);
  }

  return 0;
}
