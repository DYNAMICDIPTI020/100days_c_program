#include"stdio.h"
float average(int a, int b, int c);

float average(int a, int b, int c){
    return (a+b+c)/3.0;
}
int main()
{
    int a,b,c;
    printf("enter the value of a,b,c =");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("the average of a,b  and c is %.2f", average(a,b,c));
    return 0;
}