/* C Program - Two Dimensional Array */
		
#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int arr[10][10], row, col, i, j;
	printf("Enter number of row for Array (max 10) : ");
	scanf("%d",&row);
	printf("Enter number of column for Array (max 10) : ");
	scanf("%d",&col);
	printf("Now Enter %d*%d Array Elements : ",row, col);
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("The Array is :\n");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
	getch();
}
