#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
void *thread_1(void *vargp);
void *thread_2(void *vargp);
void *thread_3(void *vargp);

   
int main() { 
    pthread_t thread_id1; 
    pthread_t thread_id2;
    pthread_t thread_id3;

    int th_1 = pthread_create(&thread_id1, NULL, thread_1, NULL); 
    int th_2 = pthread_create(&thread_id2, NULL, thread_2, &thread_id1); 
    int th_3 = pthread_create(&thread_id3, NULL, thread_3, &thread_id2); 

    if (!th_1){
        printf("Thread 1 is created, tid is: %lu\n", thread_id1);
    }
    if (!th_2){
        printf("Thread 2 is created, tid is: %lu\n", thread_id2);
    }    
    if (!th_3){
        printf("Thread 3 is created, tid is: %lu\n", thread_id3);
    } 
    pthread_join(thread_id3, NULL); 

    return 0;
}

void *thread_1(void *vargp) {     
    printf("I am thread 1, my id is: %lu \n", pthread_self()); 
    pthread_exit(NULL);
} 

void *thread_2(void *vargp) { 
    pthread_t id = *((pthread_t*)vargp);
    pthread_join(id, NULL);
    printf("I am thread 2, my id is: %lu \n", pthread_self()); 
    pthread_exit(NULL);
} 

void *thread_3(void *vargp) { 
    pthread_t id = *((pthread_t*)vargp);
    pthread_join(id, NULL);
    printf("I am thread 3, my id is: %lu \n", pthread_self()); 
    pthread_exit(NULL);
} 