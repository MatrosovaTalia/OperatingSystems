#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

int main() {
    /* There was a declaration of a pointer to a string without memory alllocation*/
    char **s = (char**)malloc(LEN); 
    *s = malloc(LEN);
    char foo[] = "Hello World";

    *s = (char*)malloc(strlen(foo));
    memcpy(*s, foo, strlen(foo));
    printf("*s is %s\n", *s); // something was wrong with closing quote and pointers
    // it is not allowed to copy strings like that : s[0] = foo; 
    memcpy(*s, foo, strlen(foo));
    printf("s[0] is also %s\n", s[0]);
    
    return (0); 
}