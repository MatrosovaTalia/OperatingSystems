#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void notify(int signal) {
    printf("The signal is: %d\n", signal);
};

int main() {
    struct sigaction handler;
    handler.sa_handler = &notify;
    sigaction(2, &handler, NULL);

    while (1) {
        continue;
    }

    return 0;
}
