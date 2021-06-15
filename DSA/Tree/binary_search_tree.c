#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;
#define MALLOC(p,n,type)\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL)\
{\
	printf("insufficient memory\n");\
	exit(0);\
}
NODE insert(int item,NODE root)
{
	NODE temp;
	NODE cur;
	NODE prev;
	MALLOC(temp,1,struct node);
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	if(root==NULL)
	return temp;
	prev=NULL;cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(item==cur->info)
		{
			printf("Duplicate items not allowed\n");
			free(temp);
			return root;
		}
		if(item<cur->info)
		cur=cur->llink;
		else
		cur=cur->rlink;
	}
	if(item<prev->info)
	prev->llink=temp;
	else
	prev->rlink=temp;
	return root;
}
NODE search(int item,NODE root)
{
	NODE cur;
	if(root==NULL)
	return NULL;
	cur=root;
	while(cur!=NULL)
	{
		if(item==cur->info)
		{
			printf("Item found\n");
			return root;
		}
		if(item<cur->info)
		cur=cur->llink;
		else
		cur=cur->rlink;
	}
	printf("Item not found\n");
	return 0;
}
void display(NODE root,int level)
{
	int i;
	if(root==NULL)
	return;
	display(root->rlink,level+1);
	for(i=0;i<level;i++)
	printf("");
	printf("%d\n",root->info);
	display(root->llink,level+1);
}

void main()
{
NODE root=NULL;
int choice,item,key;
clrscr();
for(;;)
{
	printf("1:Insert		2:Search\n");
	printf("3:Display	4:Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("Enter the item to be inserted\n");
		scanf("%d",&item);
		root=insert(item,root);
		break;
		case 2:printf("Enter the item to be searched\n");
		scanf("%d",&item);
		root=search(item,root);
		break;
		case 3:if(root==NULL)
		printf("Tree is empty\n");
		else
		{
			printf("The given tree is\n");
			display(root,1);
			printf("\n");
		}
		break;
		default:exit(0);
	}
}
}




