/*fibonacci
*chrisme1320
*22/08/2016
*Calcula el numero de fibonacci n que se pasa por consola de manera recursiva
*/

#include <stdio.h>
#include <unistd.h>

int fibonacci(unsigned long long int n,
				unsigned long long int *memoization)
{
	if(memoization[n]!=0||n==0){
		return memoization[n];
	}
	memoization[n]=fibonacci(n-1,memoization)+fibonacci(n-2,memoization);
	
	return memoization[n];
}

int main (int argc, char **argv){
	unsigned long long int memoization[100]={0,1,0};
	printf("%d \n",fibonacci(atoi(argv[1]),memoization));
	return 0;
}