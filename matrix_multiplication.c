#include"stdio.h"
int main()
{
	int row , col , i , j ;
	printf("Enter the number of rows :\n");
	scanf("%d", &row);
	printf("Enter the number of cols :\n");
	scanf("%d", &col);
	int arr[row][col];
	int brr[row][col];
	int crr[row][col];
	
	printf("Enter %d no  of elements to the 1st matrix:\n", row*col);
	for(i = 0 ; i < row; i ++){
		for(j = 0 ; j < col ; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	printf("Enter %d of elements to the second matrix:\n ", row*col);
	for(i = 0 ; i <row ; i ++){
		for(j = 0 ; j < col ; j++){
			scanf("%d", &brr[i][j]);
		}
	}
	printf("After the multipli cation the matrix result is :\n");
	for(i = 0 ; i < row; i++){
		for(j = 0 ; j < col ; j++){
			crr[i][j] = arr[i][j] * brr[i][j];
		}
	}
	for(i = 0 ; i < row;i++)
	{
		for(j = 0 ; j < col ; j++)
		{
			printf("%d\t", crr[i][j]);
		}
		printf("\n");
	}
	
			
				
}
