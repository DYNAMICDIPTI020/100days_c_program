#include"stdio.h"
int main()
{
	int i , n , arr[100];
	
	printf("Enter the size of the array:\n");
	scanf("%d", &n);
	
	for(i = 0 ; i < n ; i++)
	{
		printf("Element %d :", i+1);
		scanf("%d", &arr[i]);
	}	
	
	printf("\n The element of the array are :\n");
	for(i = 0 ; i < n ; i++)
	{
		printf("%d\t", arr[i]);
	}
	
	printf("\n");
	return 0 ;\
}
	
