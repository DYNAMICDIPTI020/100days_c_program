#include"stdio.h"
float c2f(float );

float c2f(float c){
    return ((c*9)/5)+32;
}
int main()
{
    float c ;
    printf("enter the degree in celcious");
    scanf("%f",&c);
    printf("celcious to fahrenhit for %f is %.2f", c,c2f(c));
}