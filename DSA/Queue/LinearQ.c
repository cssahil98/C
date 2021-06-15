#include<stdio.h>
#include<process.h>
#define QUE_SIZE 5
void insertQ();
int deleteQ();
void display();
int front=-1,rear=0;
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
			if(front==-1)
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
	if(rear==QUE_SIZE-1)
	{
		printf("Queue overflow\n");
		return;
	}
	rear=rear+1;
	q[rear]=item;
}

int deleteQ()
{
	int item;
	if(front>rear)
	{
		print("Queue overflow\n");
		return-1;
	}
	else
	front=front+1;
	return q[front];
}

void display()
{
	int i;
	if(front>rear)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The content of the queue are\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\n",q[i]);

	}
}
