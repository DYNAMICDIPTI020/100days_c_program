#include "stdio.h"
int main ()
{
	int row , col ,i , j;
	printf("Enter the no of row you want :");
	scanf("%d",&row);
	printf("Enter the no of  col you want :");
	scanf("%d",&col);
	int arr[row][col];
	int trr[row][col];
	printf("Enter %d number of element :",row*col);
	for (i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("The array is looks like before transpose :\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",arr[i][j]);
		}
	printf("\n");
	}
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			trr[i][j]=arr[j][i];
		}
	}
	printf("The array is looks like after transpose :\n");
	
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d\t",trr[i][j]);
		}
		printf("\n");
	}
}