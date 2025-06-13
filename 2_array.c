#include"stdio.h"
int main(){
    int marks[5];

    printf("enter marks of 5 members\n");
    scanf("%d", &marks[0]);
    scanf("%d", &marks[1]);
    scanf("%d", &marks[2]);
    scanf("%d", &marks[3]);
    scanf("%d", &marks[4]);

    marks[0] = 45;
    marks[1] = 95;
    printf("marks 0 and marks 1 is %d %d ", marks[0], marks[1]);
    return 0;
}