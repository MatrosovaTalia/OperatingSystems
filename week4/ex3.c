#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#include <sys/types.h> 

int main(){
    char str[128];

    while(1){
        printf("> ");
        scanf("%s", str);
        system(str);
    }
    return 0;
}