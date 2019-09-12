#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main() {
    int isParent = fork();
    if (isParent == 0)
        printf("Hello from Child %d\n", getpid());
    else
        printf("Hello from Parent %d\n", getpid());

    return 0;
} 
