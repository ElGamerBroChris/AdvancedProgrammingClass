/*
author: chrisme1320
*/
#include "operation.h"
#include <stdio.h>
#include <string.h>
int main()
{
	char msg[]="What is the operation?";
  char * operation_names[]={
  													"sum",
  													"subtract",
  													"div"
  													};
  float(*operations[])(float, float)={
  																		sum,
  																		subtract,
  																		division
  																		};
	char operation[10];
	float operator1,operator2,result;
  size_t nelem=sizeof(operation_names)/sizeof(char *);//size_t=entero positivo
  int i;

	while(1)
	{
		printf("%s\n", msg);
		scanf("%s", &operation[0]);//or scanf("%s", operation);
	  tolower_string(operation);
	  if(strcmp(operation,"finish")==0)
	    break;

    for(i=0;i<nelem;i++)
    {
      if(strcmp(operation,operation_names[i])==0)
        break;
    }
	  if(i==nelem)
	  {
	    printf("Operation %s not valid \n",operation);
	    continue;
	  }
	  scanf("%f %f",&operator1,&operator2);
	  printf("Result: %.1f\n", (operations[i])(operator1,operator2));
		/*if(strcmp(tolower_string(operation),"sum")==0)
		{
			scanf("%f %f",&operator1,&operator2);
			printf("Result: %.1f\n", (operations[0])(operator1,operator2));
		}
		else if(strcmp(tolower_string(operation),"subtract")==0)
		{
			scanf("%f %f",&operator1,&operator2);
			printf("Result: %.1f\n", (operations[1])(operator1,operator2));
		}
		else if(strcmp(tolower_string(operation),"finish")==0)
			break;*/
	}
	return 0;
}
