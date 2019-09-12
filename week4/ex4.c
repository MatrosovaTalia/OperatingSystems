#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <fcntl.h> 
#include <sys/wait.h>

#define LINE_SIZE 1024

int main(){
    char s[LINE_SIZE];
    char *argv[256];

    while (1) {
        /* Starting shell, read command, tokenize command*/
        printf(">> ");
        fgets(s, LINE_SIZE, stdin);        
        argv[0] = strtok(s, " \n");

        /* read arguments*/
        int     argC = 1;
        int     childPid, state;

        /* Read arguments till the end of a line*/
        while ((argv[argC] = strtok(NULL, " \n"))) {
            argC++;
        }
        argv[argC] = NULL;
        int childPid = fork();
        if (childPid == 0) { // handle chilf fork
            int error = execvp(argv[0], argv);
            if (error) {
                printf("Error occured while starting child process: %d\n", error);
            }
            return error; // will be "return 0" if everything is OK
        } else {
            waitpid(childPid, &state, 0);
        }
    }
    return 0;
}