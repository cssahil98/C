#include<stdio.h>
#include<conio.h>
int linearsearch(int a[],int l,int h,int k)
{
	if(l>h)
	return -1;
	if(k==a[l])
	return l;
	linearsearch(a,l+1,h,k);
}

void main()
{
	int a[20],n,i,k;
	clrscr();
	printf("Enter the n value\n");
	scanf("%d",&n);
	printf("Enter the %d element \n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the key to be search\n");
	scanf("%d",&k);
	i=linearsearch(a,0,n-1,k);
	if(i!=-1)
	printf("Element found at position %d",i);
	else
	printf("Element not found");
	getch();
}
