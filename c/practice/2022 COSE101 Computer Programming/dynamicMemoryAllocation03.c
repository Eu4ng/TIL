/*
정수 N을 입력 받고, N개의 공백 없는 문자열을 입력 받아 사
전 순으로 출력하는 프로그램을 동적 할당을 사용해서 작성하
시오. 단, 문자열의 길이는 최대 99 이며, 소문자만 입력된다고
가정한다.

입력 예시
4
apricot
peach
willow
birch

출력 예시
apricot
birch
peach
willow
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int N;
    char tmp[100];
    char **str = NULL;
    char *p;
    int i, j, len, index;

    scanf("%d", &N);
    
    str = (char **) malloc(N * sizeof(char *));

    for(i=0; i<N; i++){
        scanf("%s", tmp);
        len = strlen(tmp);

        str[i] = (char *) malloc((len + 1) * sizeof(char));
        strcpy(str[i], tmp);
    }

    for(i=0; i<N; i++){
        index = i;
        for(j=i+1; j<N; j++){
            if(strcmp(str[index], str[j]) > 0){
                index = j;
            }
        }

        p = str[i];
        str[i] = str[index];
        str[index] = p;

        printf("%s\n", str[i]);
    }

    return 0;
}