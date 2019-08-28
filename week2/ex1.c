#include <limits.h>
#include <stdio.h>
#include <float.h>

int main(){
	int myInt = INT_MAX;
	float myFloat = FLT_MAX;
	double myDouble = DBL_MAX;
	printf("int size: %zu, int value: %d \n", sizeof(myInt), myInt);
	printf("float size: %zu, float value: %f \n", sizeof(myFloat), myFloat);
	printf("double size: %zu, double value: %f \n", sizeof(myDouble), myDouble);
}

