#include"stdio.h"

void sum()
{
    int a ,b , sum = 0;
    printf("enter the value of a and b\n");
    scanf("%d%d",&a,&b);
    sum = a + b;
    printf("sum of a and b is %d\n",sum);
}
void main()
{
    sum();
    printf("hello world\n");    
    sum();
}