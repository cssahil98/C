#include<stdio.h>
#include<conio.h>
void bubblesort(int a[],int n)
{
	int i,j,temp;
	if(n==1)
	return;
	{
	for(j=1;j<n;j++)
	{
	for(i=0;i<n-j;i++)
	{
	if(a[i]>a[i+1])
	{
	temp=a[i];
	a[i]=a[i+1];
	a[i+1]=temp;
	}
	}
	}
	}
	bubblesort(a,n-1);
}

void main()
{
	int a[50],n,i;
	clrscr();
	printf("Enter the n value\n");
	scanf("%d",&n);
	printf("Enter the %d element\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	bubblesort(a,n);
	printf("after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	getch();
}
