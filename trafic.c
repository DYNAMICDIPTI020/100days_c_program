#include"stdio.h"
int main()
{
    char signal;
    printf("Enter a signal (1 for green, 2 for yellow, 3 for red): ");
    scanf("%c", &signal);
    if(signal == '1')
    {
        printf("You can go.\n");
    }
    else if(signal == '2')
    {
        printf("Please slow down.\n");
    }
    else if(signal == '3')
    {
        printf("You must stop.\n");
    }
    else
    {
        printf("Invalid signal.\n");
    }
}