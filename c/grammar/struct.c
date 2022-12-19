#include <stdio.h>

// Define struct then typedef
struct student {
    int id;
    char name[8];
    double grade;
};

typedef struct student STUDENT;

// Define struct with typedef
typedef struct teacher {
    int id;
    char name[8];
} TEACHER;

int main(){
    
    struct student st1 = {10, "Tom", 3.2};
    STUDENT st2 = {20, "Alex", 4.0};

    struct teacher t1 = {30, "John"};
    TEACHER t2 = {40, "John"};

    printf("%d\n", st1.id);
    printf("%d\n", st2.id);
    printf("%d\n", t1.id);
    printf("%d\n", t2.id);

    return 0;
}