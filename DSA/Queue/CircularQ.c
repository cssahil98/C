#include<stdio.h>
#include<process.h>
#define QUE_SIZE 5
void insertQ();
int deleteQ();
void display();
int front=0,rear=-1,count=0;
int item,q[QUE_SIZE];
void main()
{
	int choice;
	clrscr();
	for(;;)
	{
		printf("1:Insert 2:Delete 3:Display 4:Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the item to be inserted\n");
			scanf("%d",&item);
			insertQ();
			break;
			case 2:item=deleteQ();
			if(item==-1)
			printf("Queue is empty\n");
			else
			printf("The deleted item is %d\n",item);
			break;
			case 3:display();
			break;
			default exit(0);
		}
	}
}

void insertQ()
{
	if(count==QUE_SIZE)
	{
		printf("Queue overflow\n");
		return;
	}
	rear=(rear+1)%QUE_SIZE;
	q[rear]=item;
	count++;
}

int deleteQ()
{
	int item;
	if(count==0)
	return-1;
	item=q[front];
	front=(front+1)%QUE_SIZE;
	count=count-1;
	return item;
}

void display()
{
	int i;
	if(count==0)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The content of the queue are\n");
	for(i=0;i<=count;i++)
	{
		printf("%d\n",q[front]);
		front=(front+1)%QUE_SIZE;
	}
}
