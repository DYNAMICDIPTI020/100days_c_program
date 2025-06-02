#include"stdio.h"
int main()
{
    int size , new, i;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    int stack[size];
    int top = -1;
    int ch;
   
    do
    {
     printf("Enter the element to add in stack: \n");
     scanf("%d", &new);
    if(top == size- 1)
    {
        printf("the stack is overflow\n");
        break;
    }
    else{
        top++;
        stack[top] = new;
        printf("Element %d pushed to stack\n", new);
    }
    printf("Enter 1 to push and 0 to pop:\n");
    scanf("%d", &ch);
    } while (ch != 0);

}
printf("The element of the stack are:\n");
for(i = 0 ; i <= top ; i++)
{
    printf("%d", stack[i]);
}

