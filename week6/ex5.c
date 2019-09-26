#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void notify(int signal) {
    printf("The signal is: %d\n", signal);
}

int main() {
    int childId;

    if ((childId = fork()) == 0) { // if the process is child
        while (1) {
            sleep(1);
            printf("I am alive\n");
        }
    }
    else {
        sleep(10);
        kill(childId, SIGTERM);
    }

    return 0;
}