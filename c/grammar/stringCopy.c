#include <stdio.h>
#include <string.h>

int main(){
    
    char strarr01[10] = "Hello";
    char strarr02[10] = "World";
    char tem[10];

    char *strptr01 = "Hello";
    char *strptr02 = "World";
    char *p;

    // String Array
    strcpy(tem, strarr01);
    strcpy(strarr01, strarr02);
    strcpy(strarr02, tem);

    printf("%s\n%s\n", strarr01, strarr02);

    // String Pointer
    p = strptr01;
    strptr01 = strptr02;
    strptr02 = p;

    printf("%s\n%s\n", strptr01, strptr02);

    return 0;
}