#include <stdio.h>

int main()
{
    int marks1, marks2, marks3;
    printf("Enter marks1: \n");
    scanf("%d", &marks1);
    printf("Enter marks2: \n");
    scanf("%d", &marks2);
    printf("Enter marks3: \n");
    scanf("%d", &marks3);
    
    if (marks1 < 33 || marks2 < 33 || marks3 < 33)
    {
        printf("You are failed due to less marks in individual subject(s)\n");
    }
    else if ((marks1 + marks2 + marks3) / 3 < 40)
    {
        printf("You are failed due to less percentage\n");
    }
    else
    {
        printf("You are passed\n");
    }
    
    return 0;
}