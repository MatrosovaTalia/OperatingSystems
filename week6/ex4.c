#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

/* Output: User defined signal 1 (ubuntu 18.04 - SIGUSR1 defined)*/
void notify(int signal) {
    printf("The signal is %d\n", signal);
}

int main() {
    struct sigaction handler;
    handler.sa_handler = &notify;
    sigaction(SIGKILL, &handler, NULL);
    sigaction(SIGSTOP, &handler, NULL);
    sigaction(SIGUSR1, &handler, NULL);

    while (1) {
        continue;
    }

    return 0;


}