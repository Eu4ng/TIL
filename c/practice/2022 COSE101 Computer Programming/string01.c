/*
다음 프로그램을 작성하시오.
문자 포인터 변수 pc를 선언하고, 다음 문자열로 초기화
"To be, or not to be : that is the question"
- 영어 소문자 't' 가 몇 번 나오는 지 계산
- 출력 : 해당 문자 t와 횟수
*/

#include <stdio.h>
#include <string.h>

int main(){
    
    char *str;
    str = "To be, or not to be : that is the question";
    int len = 0, count = 0, i;

    while(str[len]){
        if(str[len] == 't'){
            count++;
        }
        len++;
    }

    printf("t %d\n", count);

    // with "strlen" in <string.h>
    count = 0;
    len = strlen(str);
    for(i=0; i<len; i++){
        if(str[i] == 't'){
            count++;
        }
    }

    printf("t %d\n", count);
    return 0;
}