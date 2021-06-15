#include<stdio.h>
#include<conio.h>
void selectionsort(int a[],int n)
{
	int j,i,temp,pos;
	if(i==j)
	return;
	{
		for(i=0;i<n-1;i++)
		{
			pos=i;
			for(j=i+1;j<n;j++)
			{
				if(a[j]<a[pos])
				pos=j;
			}
			temp=a[pos];
			a[pos]=a[i];
			a[i]=temp;
		}
	}
}

void main()
{
	int a[50],n,i;
	clrscr();
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	selectionsort(a,n);
	printf("After sorting\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	getch();
}
