/*
사용자로부터 정수 N을 입력 받고, N 줄의 공백을 포함하는
문자열을 동적할당을 이용해 입력 받으시오. 그 후, 이 중 가장
길이가 작은 공백을 포함하는 문자열을 출력하는 프로그램을
작성 하시오. 단, 문자열의 길이는 최대 99 이다.

입력 예시
4
Program
Good
This is string
language

출력 예시
Good
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int N;
    char tmp[100];
    char **str = NULL;
    int i, j, len, min = 99, index;

    scanf("%d", &N);
    getchar();
    
    str = (char **) malloc(N * sizeof(char *));

    for(i=0; i<N; i++){
        fgets(tmp, sizeof(tmp), stdin);
        len = strlen(tmp);
        tmp[len-1] = '\0';
        len -= 1;

        if(min >= len){
            min = len;
            index = i;
        }

        str[i] = (char *) malloc((len + 1) * sizeof(char));
        strcpy(str[i], tmp);
    }

    printf("%s", str[index]);

    return 0;
}