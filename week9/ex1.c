#include <stdio.h>
#include <stdlib.h>

#define N 100 // number of page frames

typedef struct{
    unsigned int counter: 8; // 8 bit counter
    unsigned int R: 1;       // R bit
    int number;              // page number
}page;

typedef struct{
    int capacity; // maximum number of pages being allocated in memory
    int size;     // number of pages currently allocated in memory
    page pages[N];
}frame;

int pageIndex(int n, frame* frame);
void updateR(int n, frame* mem);
int updateCounters(frame* mem);

int main(){
    int hitCounter = 0;
    int missCounter = 0;

    frame mem;
    mem.capacity = N;
    mem.size = 0;

    FILE* file = fopen("Lab 09 input.txt", "r");
    if(file == NULL){
        printf("Cannot open the file");
        return 0;
    }
    int ref_page_number;


    // counters are updates on each page reference
    while (1){  
        fscanf (file, "%d", &ref_page_number);     
        if(feof(file)){break;};
        int pageInd = pageIndex(ref_page_number, &mem);
        if (pageInd == -1){ // if page fault occures
            missCounter++;

            // if there is a free page frame
            if (mem.size < mem.capacity){  
                // create new page, add to the frame
                page newPage;
                newPage.number = ref_page_number;
                newPage.R = 1;
                newPage.counter = 0;
                mem.pages[mem.size] = newPage;

                mem.size++;
            }
            else{  // if all page frames are occupied
                   // find a page with the lowest counter
                int min = mem.pages[0].counter;
                int minIndex = 0;
                for (int i = 1; i < mem.size; i++){
                    if (mem.pages[i].counter < min){
                        minIndex = i;
                        min = mem.pages[i].counter;
                    }
                }
                // replace it with a new page
                mem.pages[minIndex].number = ref_page_number;
                mem.pages[minIndex].R = 1;
                mem.pages[minIndex].counter = 0;
            }
        }
        else{ // if no page fault occures
            mem.pages[pageInd].R = 1;
            hitCounter++;
        }
        updateR(ref_page_number, &mem); // update R bits                
        updateCounters(&mem);           // update counters

    }
    fclose (file);

    printf("hits: %d, misses: %d, ratio: %f\n", hitCounter, missCounter,
                                (float)hitCounter/(float)missCounter);
    /*For frame size 10: hits: 10, misses: 990, ratio: 0.010101 
      For frame size 50: hits: 51, misses: 949, ratio: 0.053741
      For frame size 100: hits: 93, misses: 907, ratio: 0.102536*/
    
}

//  @returns <i> index of page in frame if it is in frame, 
//  @param <n> refernce page's number 
//  @param <frame> virtual frame */
int pageIndex(int n, frame* frame){   
    for (int i = 0; i < frame->size; i++){
        if (frame->pages[i].number == n){
            return i;
        }
    }
    return -1;
}

// Sets all R bits except page number <n> to 0
void updateR(int n, frame* mem){ 
    for(int i = 0; i < mem->size; i++){
        if (mem->pages[i].number != n){
            mem->pages[i].R = 0;
        }
    }
}

int updateCounters(frame* mem){
    for (int i = 0; i < mem->size; i++){
        mem->pages[i].counter >>= 1;
        mem->pages[i].counter += 128 * mem->pages[i].R;
    }
}