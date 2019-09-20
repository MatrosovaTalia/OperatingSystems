#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define empty 0
#define full 100

int producer_sleep = 0;
int consumer_sleep = 0;

int current_value = 0;

void *produce(void *arg);
void *consume(void *arg);

int main(){
    pthread_t producer; 
    pthread_t consumer;

    producer = pthread_create(&producer, NULL, produce, NULL); 
    consumer = pthread_create(&consumer, NULL, consume, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    return 0;
}

void *produce(void *arg) { 
    while(1){
        while(producer_sleep){
            continue;
        }
        if (current_value < full){
            current_value++;
            // printf("I produce, current value is %d\n", current_value);
        }
        else{
            consumer_sleep = 0;
            producer_sleep = 1;
        }
    }    
    pthread_exit(NULL);

} 

void *consume(void *arg){
    while(1){
        while(consumer_sleep){
            continue;
        }
        if(current_value > empty){
            current_value--;
            // printf("I consume, current value is %d\n", current_value);
        }
        else{
            producer_sleep = 0;
            consumer_sleep = 1;
        }
    }
    pthread_exit(NULL);
}