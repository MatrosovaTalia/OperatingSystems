#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define MB 1024 * 1024
#define zero 0

int main(){
    struct rusage resource_usage;
    for (int i = 0; i < 10; i++){
        char *p = malloc(10 * MB); 
        memset(p, zero, 10 * MB);  
        getrusage(RUSAGE_SELF,&resource_usage);
        printf("Memory usage = %ld\n", resource_usage.ru_maxrss);
        sleep(1);
    }
    return 0;
    /*
    Memory usage = 11212
    Memory usage = 21680
    Memory usage = 31976
    Memory usage = 42272
    Memory usage = 52568
    Memory usage = 62864
    Memory usage = 72896
    Memory usage = 83192
    Memory usage = 93488
    Memory usage = 103784*/
}
