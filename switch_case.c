#include"stdio.h"
int main()
{
    int a;
    printf("enter a :");
    scanf("%d",&a);
    switch(a){
        case 1:
            printf("you enter 1\n");
            break;
        case 2:
            printf("you are second\n");
            break;
        case 3:
            printf("you are third\n");
            break;
        case 4:
            printf("you are fourth\n");
            break;
        case 5:
            printf("you are fifth\n");
            break;
        case 6:
            printf("you are sixth\n");
            break;
        default:
            printf("fucku");
            break;
    }
}