/*
5명 학생의 이름과 기말고사 점수를 입력 받아, 구조체 배열에
저장 한 후, 평균 이하의 점수를 받은 학생의 이름을 출력하는
프로그램을 작성하시오. 단, 학생의 이름은 공백 없이 최대 9개
영어 문자이다.

입력 예시
akim 75
bkim 85
ckim 65
dkim 95
ekim 100

출력 예시
akim
bkim
*/

#include <stdio.h>

typedef struct student {
    char name[10];
    int score;
} STUDENT;

int main(){

    STUDENT std[5];
    int sum = 0;
    float avg;
    int i;

    for(i=0; i<5; i++){
        scanf("%s %d", std[i].name, &std[i].score);
    }

    for(i=0; i<5; i++){
        sum += std[i].score;
    }

    avg = sum / 5.0;

    for(i=0; i<5; i++){
        if(std[i].score < avg){
            printf("%s\n", std[i].name);
        }
    }

    return 0;
}