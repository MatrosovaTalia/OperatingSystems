#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h>

#define LINESIZE 100

int main() {
    int pipefd[2];
    pipe(pipefd);
    int firstChild = fork();
    int secondChild = fork();

    if (firstChild == 0) {
        int pid;
        char str[LINESIZE];

        printf("First child created\n");
        read(pipefd[0], str, LINESIZE);
        sscanf(str, "%d", &pid);
        printf("Reading second child pid from pipe: %d\n", pid);
        sleep(5);
    }
    else {
        if (secondChild == 0) {
            printf("Second child created\n");
            while (1) {
                sleep(1);
                printf("Hello, I am second\n");
            }
        }
        else {
            char str[LINESIZE];
            sprintf(str, "%d", secondChild);
            printf("Sending second child pid to pipe: %d\n", secondChild);
            write(pipefd[1], str, LINESIZE);

            printf("Changing states wait\n");
            waitpid(secondChild, NULL, WUNTRACED);
            printf("Done waiting\n");
        }
    }

    return 0;
}