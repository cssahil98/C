#include<stdio.h>
#include<process.h>
#define STACK_SIZE 5


int top;
int s[10];
int item;
void push();
int pop();
void display();
void main()
{
      int item_deleted;
      int choice;
      clrscr();
      top=-1;
      for(;;)
      {
	printf("1:PUSH 2: POP 3: DISPLAY 4:EXIT\n");
	printf("Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("Enter the item to be inserted\n");
		scanf("%d",&item);
		push();
		break;
		case 2:
		item_deleted=pop();
		if(item_deleted==-1)
		printf("Stack is empty\n");
		else
		printf("item_deleted=%d\n",item_deleted);
		break;
		case 3:display();
		break;
		default:
		exit(0);
		getch();
	}
       }
}

void push()
{
	if(top==STACK_SIZE-1)
	{
	      printf("Stack Overflow\n");
	      return;
	}
	top=top+1;
	s[top]=item;
}

int pop()
{
	if(top==-1)
	return -1;
	return s[top--]
}

void display()
{
	int i;
	if(top==-1)
	{
	     printf("Stack is empty\n");
	     return;
	}
	printf("Content of the Stack is\n");
	for(i=0;i<=top;i++)
	{
	     printf("%d\n",s[i]);
	}
}
