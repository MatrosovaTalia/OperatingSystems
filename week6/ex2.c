#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define LINESIZE 32

int main() {
    int pipefd[2];

    pipe(pipefd);

    if (fork() == 0) { // if process is a child    
        char str[LINESIZE] = "";
        read(pipefd[0], str, LINESIZE);
        printf("%s\n", str);
    }
    else {
        char str[LINESIZE] = "Hello, I've read it!";
        write(pipefd[1], str, LINESIZE);
    }
    return 0;
}