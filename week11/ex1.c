#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
 
int main()
{
    int filedesc = open("ex1.txt", O_RDWR);
    if(filedesc < 0){
        printf("Cannot open ex1.txt\n");
    }

    struct stat fdStat = {};
    if (fstat(filedesc, &fdStat)){
        printf("fstat(filedesc, &fdStat) failed\n");
    }

    off_t size = fdStat.st_size;
    char *addr;
    addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, filedesc, 0);
    
    if (addr == MAP_FAILED){
        printf("mmap failed\n");
    }
    
    int i = 0;
    while(addr[i] != 'g'){
        i++;
    }

    addr[i] = 'n';
    i++;
    addr[i] = 'i';
    i++;
    addr[i] = 'c';
    i++;
    addr[i] = 'e';
    i++;
    
    return 0;
}