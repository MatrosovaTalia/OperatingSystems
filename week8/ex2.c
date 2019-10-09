#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB 1024 * 1024
#define zero 0

int main(){
    for (int i = 0; i < 100; i++){
        void *p = malloc(10 * MB); // allocate 10 Mb
        memset(p, zero, 10 * MB);  // set to 0
        sleep(1);
    }
    /* There are 0s in si/so because the swap space is not used*/
}
