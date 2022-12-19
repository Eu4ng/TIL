#include <stdio.h>
#include <string.h>

typedef struct student {
    int id;
    char name[8];
    double grade;
} STUDENT;

void main( ){

    STUDENT st1 = {10, "Tom", 3.2};
    STUDENT *pst = &st1;

    // pst->id 는 (*pst).id와 동일하다
    pst->id += 20;
    strcpy(pst->name, "alice");
    pst->name[0] = 'A';
    printf("id: %d\n", pst->id);
    printf("name: %s\n", pst->name);
    printf("grade: %.2f\n", pst->grade);

    return 0;
}