#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;
#define MALLOC(p,n,type)		\
p=(type*)malloc(n*sizeof(type));		\
if(p==NULL)				\
{					\
	printf("Insufficient memmory\n");      \
	exit(0);			       \
}
//FUNCTION TO INSERT A NODE AT THE FRONT END OF THE LIST//
NODE insert_front(int item, NODE head)
{
	NODE temp,cur;
	MALLOC(temp,1,struct node);
	temp->info=item;
	cur=head->rlink;
	head->rlink=temp;
	temp->llink=head;
	temp->rlink=cur;
	cur->llink=temp;
	return head;
}
//FUNCTION TO INSERT TO THE LEFT OF A SPECIFIED  NODE//
NODE insert_left(int item,NODE head)
{
	NODE temp,cur,prev;
	if(head->rlink==head)
	{
		printf("List is empty\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(item==cur->info)
		break;
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("Key not found\n");
		return head;
	}
	prev=cur->llink;
	printf("Enter the item to be insert towards left of %d=",item);
	MALLOC(temp,1,struct node);
	scanf("%d",&temp->info);
	prev->rlink=temp;
	temp->llink=prev;
	cur->llink=temp;
	temp->rlink=cur;
	return head;
}
//FUNCTION TO DELETE A NODE WHOSE INFO IS PROVIDED//
NODE delete_item(int item,NODE head)
{
	NODE prev,cur,next;
	if(head->rlink==head)
	{
		printf("List is empty can not delete\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(item==cur->info)
		break;
		cur=cur->rlink;
	}
	if(cur==head)
	{
		printf("Item not found\n");
		return head;
	}
	prev=cur->llink;
	next=cur->rlink;
	prev->rlink=next;
	next->llink=prev;
	free(cur);
	return head;
}
//FUNCTION TO DISPLAY THE CONTENT OF THE LIST//
void display(NODE head)
{
	NODE temp;
	if(head->rlink==head)
	{
		printf("Deque is empty\n");
		return;
	}
	printf("The content of list\n");
	temp=head->rlink;
	while(temp!=head)
	{
		printf("%d\n",temp->info);
		temp=temp->rlink;
	}
}

void main()
{
	NODE head;
	int choice,item;
	clrscr();
	MALLOC(head,1,struct node);
	head->rlink=head;
	head->llink=head;
	for(;;)
	{
		printf("1:Insert_front 2:Insert_left 3:Delet_info 4:display 5:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the item to be inserted\n");
			scanf("%d",&item);
			head=insert_front(item,head);
			break;
			case 2:
			printf("Enter the key\n");
			scanf("%d",&item);
			head=insert_left(item,head);
			break;
			case 3:
			printf("Enter the key to be deleted\n");
			scanf("%d",&item);
			head=delete_item(item,head);
			break;
			case 4:display(head);
			break;
			default:
			exit(0);
		}
		getch();
	}
}

