#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	/*Assume tha input has correct structure, if it is not I would add a special check*/
	printf("Enter two integers: ");
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d \n", a, b);
}
