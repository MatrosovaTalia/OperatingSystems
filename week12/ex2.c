#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int tee(int appendFileFlag, char *fileName);

int main(int argc, char *argv[]) {
    // handle wrong input
    if (argc <= 1) {
        fprintf(stderr, "wrong input\n");
        return 1;
    }

    int appendFlag = 0;
    int executableOptions = -1;

    // Store a reference pointer in memory to store the filename
    char *fileName = NULL;
    // handle -a case
    while ((executableOptions = getopt(argc, argv, "a:")) != -1) {
        switch(executableOptions) {
            case 'a':
                appendFlag = 1;
                fileName = optarg;
                break;
            default:
                fprintf(stderr, "wrong input");
                return 1;
        }
    }

    if (0 == appendFlag) {
        return tee(appendFlag, argv[1]);
    }
    return tee(appendFlag, fileName);
}

int tee(int appendFlag, char *file) {
    ssize_t bytesRead, writeStatus;

    int inFd;
    int outFd;
    char buffer[BUF_SIZE];
    memset(buffer, 0, sizeof(buffer));
    outFd = open(file, O_WRONLY | O_CREAT | 
    (appendFlag ? O_APPEND: O_TRUNC), S_IRWXU);

    int errnoSaved = errno;
    if (0 > outFd) {
        fprintf(stderr, "Error occured: %d\n", errnoSaved);
        fprintf(stderr, "Cannot open file: %s\n", file);
        return -1;
    }

    inFd = 0;
    while ((bytesRead = read(inFd, buffer, BUF_SIZE)) > 0) {
        writeStatus = write(outFd, buffer, (size_t) bytesRead);

        errnoSaved = errno;
        if (-1 == writeStatus) {
            fprintf(stderr, "Error occured: %d\n", errnoSaved);
            fprintf(stderr, "Couldn't write to file: %s\n", file);
            return -1;
        }
        // print to stdout and outputfile
        fprintf(stdout, "%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    errnoSaved = errno;
    if (-1 == bytesRead) {
        fprintf(stderr, "Error occured: %d\n", errnoSaved);
        fprintf(stderr, "Cannot read bytes from pipe %s\n", file);
        return -1;
    }
    return close(outFd);
}