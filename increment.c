#include"stdio.h"
int main()
{
	int first , second , third ;
	first = 5 ;
	second = ++first;
	third = second--;
	printf(" %d %d %d ",first , second , third );
}