#include <stdio.h>

void bubbleSort(int* arr, int len);

int main(){
    int arr[10] = {10, 23, 5, 4, 6, 89, 1, 0, 99, 8};
    int len = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, len);
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);

}

/** Sorts an array of integers of given length in descending order
*/
void bubbleSort(int* arr, int len){
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            if(arr[j] > arr[i] ){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}