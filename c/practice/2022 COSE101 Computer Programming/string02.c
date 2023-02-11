/*
사용자로부터 공백을 포함하지 않는 문자열 2개를 받아서, 이
들 문자열이 일치하는지를 검사하는 프로그램을 작성하시오.
- 단, 표준 문자열 처리 함수 사용금지
- 입력 받는 2개의 문자열 길이는 최대 99이다.
- 첫 번째 문자열의 길이를 출력하고, 일치하면 1 불일치하면 0을 출력

입력 예시
Hello
world

출력 예시
5 0

입력 예시 2
programming
programming

출력 예시 2
11 1
*/

#include <stdio.h>

int main(){

    char str[2][100];
    int len = 0, result = 1;
    int i;

    for(i=0; i<2; i++){
        scanf("%s", str[i]);
    }

    while(str[0][len]){
        len++;
    }

    for(i=0; i<len; i++){
        if(str[0][i] != str[1][i]){
            result = 0;
            break;
        }
    }

    printf("%d %d\n", len, result);

    return 0;
}