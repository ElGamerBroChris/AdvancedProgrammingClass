/*fibonacci
*chrisme1320
*22/08/2016
*Calcula el numero de fibonacci n que se pasa por consola de manera recursiva
*/

#include <stdio.h>
#include <unistd.h>

int fibonacci(int n){
  if(n==0||n==1){
    return n;
  }
  return fibonacci(n-1)+fibonacci(n-2);
}

int main (int argc, char **argv){
  printf("%d \n",fibonacci(atoi(argv[1])));
  return 0;
}
