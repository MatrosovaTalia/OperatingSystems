#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Corrected declaration of a pointer without memory alllocation*/
    char **s = (char**)malloc(sizeof(char*)); 
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n", *s); // something was wrong with closing quote
    // it is not allowed to copy strings like that : s[0] = foo; 
    memcpy(*s, foo, strlen(foo));
    printf("s[0] is %s\n", s[0]);
    
    return (0); 

    /* s is Hello World
       s[0] is Hello World
    */
}