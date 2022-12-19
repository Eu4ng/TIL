#include <stdio.h>
#include <stdlib.h>

int main(){
    
    // 포인터 선언 및 NULL 초기화
    int *ptr = NULL;

    // 동적 할당
    ptr = (int *) malloc(sizeof(int));
    //ptr = (int*) calloc(1, sizeof(int));
    //ptr = (int*) realloc(ptr, sizeof(int));

    // 동적 할당 오류 검사
    if(ptr == NULL){
        printf("NOT ENOUGH MEMORY !\n");
        return -1;
    }

    // 할당된 메모리 사용
    *ptr = 20;

    printf("%d", *ptr);

    // 할당 받은 메모리 해제
    free(ptr);

    // 포인터 NULL 초기화: 해제된 메모리 영역이 우연찮게 다른 곳에서 사용되는 경우를 막기 위해
    // Dangling Pointer
    ptr = NULL;

    return 0;
}