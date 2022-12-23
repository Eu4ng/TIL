#include <stdio.h>

int main(){
    
    char strarr[10] = "Hello";
    char *strptr = "Hello";

    strarr[5] = '!';
    printf("%s\n", strarr);
    
    strptr = "Hello!";
    printf("%s\n", strptr);

    return 0;
}