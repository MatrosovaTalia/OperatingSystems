#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void *myRealloc(void *ptr,size_t oldSize, size_t newSize);

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
	a1 =(int*) myRealloc((void*)a1, sizeof(int) * n1, sizeof(int) * n2);

    /* Check the result */
	for(i = 0; i < n2; i++){
		printf("%d ", a1[i]);
	}
	printf("\n");
	return 0;
}

void *myRealloc(void *ptr,size_t oldSize, size_t newSize){
    if (newSize == 0){      // acts like free if new size is 0
        free(ptr);
        return NULL;
    }    
    else if (ptr == NULL){  // act like malloc(newSize) is the pointer is NULL
        ptr = malloc(newSize);
        return ptr;
    }
    else if(newSize <= oldSize){
        return ptr; 
    }
    else{  // if newSize > oldSize
        void *newPtr = malloc(newSize);    // allocates new memory
        if(newPtr){
            memcpy(newPtr, ptr, newSize);  // copies the existing data to newly allocated memory
            free(ptr);                     // frees the passed pointer
        }
        return newPtr;  // returns the pointer to the newly allocated memory
    }
}