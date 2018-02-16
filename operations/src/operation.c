/*
author: chrisme1320
*/
#include <ctype.h>
#include <string.h>
#include "operation.h"

float sum(float a,float b)
{
	return a+b;
}
float subtract(float a,float b)
{
	return a-b;
}
float division(float a, float b)
{
	return a/b;
}
char * tolower_string(char *s){
	int i;
	for(i=0;i<strlen(s);i++)
		s[i]=tolower(s[i]);
	return s;
}