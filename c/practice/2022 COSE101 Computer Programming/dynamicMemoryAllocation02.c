/*
사용자로부터 정수 N을 입력 받고, N 줄의 공백을 포함하는 문자열을 동적
할당을 이용해 입력받으시오. 그 후, 이 중 가장 길이가 긴 문자열부터 가장
길이가 작은 문자열까지 정렬하고, 순서대로 출력하는 프로그램을 작성하
시오. 단, 문자열의 길이는 최대 99 이고, 같은 길이의 문자열은 없다고 가
정한다.

입력 예시
4
Program
Good
This is string
Language

출력 예시
This is string
Language
Program
Good
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
    getchar();
    
    str = (char **) malloc(N * sizeof(char *));

    for(i=0; i<N; i++){
        fgets(tmp, sizeof(tmp), stdin);
        len = strlen(tmp);
        tmp[len-1] = '\0';
        len -= 1;

        str[i] = (char *) malloc((len + 1) * sizeof(char));
        strcpy(str[i], tmp);
    }

    for(i=0; i<N; i++){
        index = i;
        len = strlen(str[i]);
        for(j=i+1; j<N; j++){
            if(strlen(str[j]) >= len){
                index = j;
                len = strlen(str[j]);
            }
        }

        p = str[i];
        str[i] = str[index];
        str[index] = p;
        printf("%s\n", str[i]);
    }

    return 0;
}