/*
N 명의 학생에 대한 정보(이름, 국어 성적, 영어 성적, 수학 성
적)를 입력 받아, 각 학생의 평균 성적에 따라 학점을 산출한
후, 각 학생의 이름과 평균 성적과 학점을 출력하는 프로그램
을 작성하시오.
- N은 1 이상 50 이하
- 학생의 이름은 공백 없이 최대 7개 영어 문자이다.
- 국어 성적, 영어 성적, 수학 성적은 0 이상 100 이하인 정수
- 평균은 소수 첫째 자리까지 출력
- 학점은 평균 성적으로 다음 기준을 적용하여 산출:
90 이상 100 이하: A
80 이상 90 미만: B
70 이상 80 미만: C
70 미만: D
- 전역 변수 사용 금지
- 반드시 구조체 포인터 사용
- 다음 멤버를 가지는 student 구조체를 정의하여 사용하시오.
이름을 저장하는 문자배열, 국어 성적을 저장하는 정수형 변수,
영어 성적을 저장하는 정수형 변수, 수학 성적을 저장하는 정수형 변수,
평균 성적을 저장하는 실수형 변수, 학점을 저장하는 문자형 변수

입력 예시
2
Kim 82 72 58
Young 90 100 99

출력 예시
Kim 70.7 C
Young 96.3 A
*/

#include <stdio.h>

typedef struct student {
    char name[8];
    int korean;
    int english;
    int math;
    float avg;
    char grade;
} STUDENT;

int main( ){

    STUDENT std[50];
    STUDENT *pst;
    int N, i;

    scanf("%d", &N);
    
    for(i=0; i<N; i++){
        scanf("%s %d %d %d", std[i].name, &std[i].korean, &std[i].english, &std[i].math);
    }

    for(i=0; i<N; i++){
        pst = &std[i];

        pst->avg = (pst->korean + pst->english + pst->math) / 3.0;

        if(pst->avg >= 90 && pst->avg <= 100){
            pst->grade = 'A';
        }
        else if(pst->avg >= 80){
            pst->grade = 'B';
        }
        else if(pst->avg >= 70){
            pst->grade = 'C';
        }
        else{
            pst->grade = 'D';
        }

        printf("%s %.1f %c\n", pst->name, pst->avg, pst->grade);
    }

    return 0;
}