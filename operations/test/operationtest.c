/*operationtest
*chrisme1320
*29/08/2016
*Hace las pruebas de operations
*/
#include "utest.h"
#include "../src/operation.h"
#include <stdio.h>

static char * test_sum(){
	float a,b,c;
	a=23.5;
	b=5.0;
	c=sum(a,b); //function testing
	assert_test("Sum must be ",c==a+b);
	return 0;
}
static char * test_subtract()
{
	float a,b,c;
	a=23.5;
	b=5.0;
	c=subtract(a,b); //function testing
	assert_test("Subtract must be ",c==a-b);
	return 0;
}
static char * test_tolower_string()
{
	char *str_test=strdup("STRING in UPPERCASE");
	char *str_expected="string in uppercase";
	char *str_result=tolower_string(str_test);
	assert_test("String must be on lower case", !strcmp(str_expected,str_result));
	return 0;
}
static char * test_division()
{
	float a,b,c;
	a=20.0;
	b=5.0;
	c=division(a,b); //function testing
	assert_test("Division must be ",c==a/b);
	return 0;
}
int main(){
	run_test("Test sum:", test_sum);
	run_test("Test subtraction: ", test_subtract);
	run_test("Test to lower case: ", test_tolower_string);
	run_test("Test division: ", test_division);
	return 0;
}
