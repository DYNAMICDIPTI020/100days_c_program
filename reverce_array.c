#include"stdio.h"
int main()
{
	int i , arr[100] , n ;
	printf("Enter the size of the array:\n");
	scanf("%d", &n);
		
	printf("Enter the element of the array:\n");	
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d", &arr[i]);
	}	
	
	printf("Before Reverse the array looks like: \n");
	for(i = 0 ; i < n ; i++)
	{
		printf("%d\t", arr[i]);
	}	
	
	printf("\nAfter the Reverse the array looks like : \n");
	for(i = n-1; i >= 0 ; i--)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0 ;	
}
