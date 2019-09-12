#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void swap(int *a, int *b);
int partition(int arr[], int left, int right);
void quicksort(int A[], int left, int right);

main(){
    

}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int left, int right) {
    
    int pivot;
    pivot = arr[right];
    
    while(1){
        while( arr[right] > pivot){
            right--;
        }
        while( arr[left] < pivot){
            left++;
        }
        if( left < right ){
            swap(arr[left], arr[right]);
            }else{
            return left;
        }
    }
}

void quicksort(int A[], int left, int right){
    int m;
    if( left < right ) {
        m = partition( A, left, right);
        quicksort( A, left, m-1);
        quicksort( A, m+1, right);
    }
}