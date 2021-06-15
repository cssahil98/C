#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*link;
};
typedef struct node*NODE;
#define MALLOC(p,n,type)		\
p=(int*)malloc(n*sizeof(int));		\
if(p==NULL)				\
{					\
	printf("Insufficient memmory\n");      \
	exit(0);			       \
}
//FUNCTION TO INSERT AN ITEM AT THE FRONT END OF THE LIST//
NODE insert_front(int item,NODE last)
{
	NODE temp;
	MALLOC(temp,1,struct node);
	temp->info=item;
	if(last==NULL)
	last=temp;
	else
	temp->link-last->link;
	last->link=temp;
	return last;
}
//FUNCTION TO INSERT AN ITEM AT THE REAR END OF THE LIST//
NODE insert_rear(int item,NODE last)
{
	NODE temp;
	MALLOC(temp,1,struct node);
	temp->info=item;
	if(last==NULL)
	last=temp;
	else
	temp->link=last->link;
	last->link=temp;
	return temp;
}
//FUNCTION TO DELETE AN ITEM FROM THE FRONT END OF THE LIST//
NODE delete_front(NODE last)
{
	NODE temp,first;
	if(last==NULL)
	{
		printf("List is empty can not delete\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("item deleted=%d\n",last->info);
		free(last);
		return NULL;
	}
	first=last->link;
	last->link=first->link;
	printf("item deleted=%d\n",first->info);
	free(first);
	return last;
}
//FUNCTION TO DELETE AN ITEM FROM REAR END OF THE LIST//
NODE delete_rear(NODE last)
{
	NODE prev;
	if(last==NULL)
	{
		printf("list is empty can not delete\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("item deleted=%d\n",last->info);
		free(last);
		return NULL;
	}
	prev=last->link;
	while(prev->link!=last)
	{
		prev=prev->link;
	}
	prev->link=last->link;
	printf("item deleted=%d\n",last->info);
	free(last);
	return prev;
}
//FUNCTION TO DISPLAY THE LIST//
void display(NODE last)
{
	NODE temp;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("The content of the list\n");
	temp=last->link;
	while(temp!=last)
	{
		printf("%d\n",temp->info);
		temp=temp->link;
	}
	printf("%d\n",temp->info);
}

void main()
{
	NODE last;
	int choice,item;
	last=NULL;
	for(;;)
	{
		printf("1:Insert_front 2:Insert_rear 3:Delet_front\n");
		printf("4:Delete_rear 5:display 6:exit\n");
		printf("Enter your choice\n");
		scanf("%D",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the item to be inserted\n");
			scanf("%d",&item);
			last=insert_front(item,last);
			break;
			case 2:
			printf("Enter the item to be inserted\n");
			scanf("%d",&item);
			last=insert_rear(item,last);
			break;
			case 3:
			last=delete_front(last);
			break;
			case 4:
			last=delete_rear(last);
			break;
			case 5:display(last);
			break;
			default:
			exit(0);
		}
	}
}

