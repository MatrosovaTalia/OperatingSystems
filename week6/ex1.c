#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
    int pipefd[2];

    char str1[32] = "Hello, I am string!";
    char str2[32] = "";   

    pipe(pipefd);    

    write(pipefd[1], str1, strlen(str1)); // write message to pipe 
    read(pipefd[0], str2, strlen(str1));  // read message from pipe 

    return 0;
}

