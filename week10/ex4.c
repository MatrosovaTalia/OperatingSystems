#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void scanDir(char *dir, int depth);

int main()
{
    scanDir("./tmp", 0);
    return 0;
}

void scanDir(char *dir, int depth){
    DIR *dp;
    struct dirent *filename;
    struct stat stat;
    if ((dp = opendir(dir)) == NULL){
        fprintf(stderr, "While opening the directory %s error occured\n", dir);
        return;
    }

    chdir(dir);
    while ((filename = readdir(dp)) != NULL){
        lstat(filename->d_name, &stat);
        if (strcmp(".", filename->d_name) == 0 || strcmp("..", filename->d_name) == 0){
            continue;
        }

        if (stat.st_nlink >= 2){
            printf("%s \n", filename->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}
