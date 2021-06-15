#include<stdio.h>
#include<conio.h>
void towers(int,char,char,char);

int main()
{
	int num;
	printf("Enter the number of disk\n");
	scanf("%d",&num);
	towers(num,'A','B','C');
	getch();
	return 0;
}

void towers(int num,char a,char b,char c)
{
	if(num>=1)
	{
		towers(num-1,a,c,b);
		printf("%d disk move %c to %c\n",num,a,b);
		towers(num-1,c,b,a);
	}
}
	
