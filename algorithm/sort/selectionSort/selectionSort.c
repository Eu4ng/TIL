#include <stdio.h>
#include <string.h>

int main(){
    
    // int
    int num[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // string (array)
    char str[4][20] = {"banana", "apple", "strawberry", "pineapple"};
    char tem_s[20];
    // string (array pointer)
    char *str_p[4] = {"bus", "can", "airplane", "quest"};
    char *p;

    int i, j, min, index, tem_i;

    // int
    for(i=0; i<10; i++){
        min = 10;
        for(j=i; j<10; j++){
            if(min > num[j]){
                index = j;
                min = num[j];
            }
        }
        
        tem_i = num[i];
        num[i] = num[index];
        num[index] = tem_i;

        printf("%d\n", num[i]);
    }

    printf("\n");

    // string (array)
    for(i=0; i<4; i++){
        index = i;
        for(j=i+1; j<4; j++){
            if(strcmp(str[index], str[j]) > 0){
                index = j;
            }
        }
        
        strcpy(tem_s, str[i]);
        strcpy(str[i], str[index]);
        strcpy(str[index], tem_s);

        printf("%s\n", str[i]);
    }

    printf("\n");

    // string (array pointer)
    for(i=0; i<4; i++){
        index = i;
        for(j=i+1; j<4; j++){
            if(strcmp(str_p[index], str_p[j]) > 0){
                index = j;
            }
        }
        
        p = str_p[i];
        str_p[i] = str_p[index];
        str_p[index] = p;

        printf("%s\n", str_p[i]);
    }

    printf("\n");

    return 0;
}