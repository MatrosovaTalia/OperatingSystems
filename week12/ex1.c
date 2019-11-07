#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    FILE* out = fopen("ex1.txt", "w");

    int data = open("/dev/random", O_RDONLY);
    if (data < 0){
        fprintf(stderr, "Cannot open /dev/random\n");
    }
    char str[20];
    size_t len = 0;
    while (len < sizeof str){
        ssize_t result = read(data, str + len, (sizeof str) - len);
        if (result < 0){
            fprintf(stderr, "Cannot read data\n");
        }
        len += result;
    }
    close(data);
    fprintf(out, "%s\n", str);
    fclose(out);
}