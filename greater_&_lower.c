#include"stdio.h"
int main()
{
	int i , arr[100],min ,max, n;
	printf("Enter the size of the array:\n");
	scanf("%d", &n);
	
	printf("Enter the element of the array:\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	max = min = arr[0];	

	for( i = 0; i < n ;i++)
	{
		if(arr[i] > max)
			{	
				max = arr[i];
			}
		if(arr[i] < min)
			{
				min = arr[i];
			}
	}		
	printf("The max element is %d and min Element is %d ", max , min);
}
