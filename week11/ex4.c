#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char *argv[]){
    char *src, *dst;
    int fdSrc, fdDst;
    struct stat fdStat;

    fdSrc = open("source.txt", O_RDONLY);
    if (fdSrc == -1){
        printf("Cannot open source.txt\n");
    }

    /* Open file and print errors that might occure */

    if (fstat(fdSrc, &fdStat) == -1)
        printf("fstat\n");

    src = mmap(NULL, fdStat.st_size, PROT_READ, MAP_PRIVATE, fdSrc, 0);
    if (src == MAP_FAILED)
        printf("mmap failed\n");

    fdDst = open("dest.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
    if (fdDst == -1)
        printf("Cannot open dest.txt\n");

    if (ftruncate(fdDst, fdStat.st_size) == -1)
        printf("ftruncate");

    dst = mmap(NULL, fdStat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fdDst, 0);
    if (dst == MAP_FAILED)
        printf("mmap failed\n");

    memcpy(dst, src, fdStat.st_size);       /* Copy bytes between mappings */

    return 0;
}