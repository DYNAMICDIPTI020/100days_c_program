#include"stdio.h"
int main()
{
	int Divs,Numb ;
	printf("Enter the number you want to divide :");
	scanf("%d", &Numb);
	printf("Enter the number you want to check Wheather it's divisible or not :");
	scanf("%d", &Divs);
	int remain = Divs % Numb;
	if(Divs % Numb == 0){
		printf("%d The number is divisible by This number %d.", Divs , Numb);
	}
	else if(Divs % Numb <= 1){
		printf("The number is not divisible by %d this number and it's remainder is %d.\n",Numb,remain);
	}
	
}
