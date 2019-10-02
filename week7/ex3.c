#include <stdlib.h>
#include <stdio.h>


int main(){
	/* Specify initial size */
	printf("Enter original array size: ");
	int n1 = 0;
	scanf("%d", &n1);

	/* Create an array of n1 ints*/
	int* a1 = (int*)malloc(sizeof(int));
	int i;
	for(i = 0; i <n1; i++){
		a1[i] = 100;		
		printf("%d ", a1[i]); 
	}

	/* Specify new size */
	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);

	/* Change size */
	a1 =(int*) realloc((void*)a1, sizeof(int) * n2);

	/* Initialize new elements to 0 (if there are)*/
	if (n2 > n1){
		for (i = n1; i < n2; i++){
			a1[i] = 0;
		}
	}

	/* Check the result */
	for(i = 0; i < n2; i++){
		printf("%d ", a1[i]);
	}
	printf("\n");
	return 0;
}
