#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_QUEUE 10
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;
#define MALLOC(p,n,type)	\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL)\
{\
	printf("Insufficient Memory\n");\
exit(0);\
}
/* FUNCTION TO TRAVERSE THE TREE IN PREORDER*/
void preorder(NODE root)
{
	if(root==NULL)
	return;
	printf("%d",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}
/* FUNCTION TO TRAVERSE THE TREE IN POSTORDER*/
void postorder(NODE root)
{
	if(root==NULL)
	return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d",root->info);
}
/* FUNCTION TO TRAVERSE THE TREE IN INORDER*/
void inorder(NODE root)
{
	if(root==NULL)
	return;
	inorder(root->llink);
	printf("%d",root->info);
	inorder(root->rlink);
}
/* C FUNCTION TO PRINT THE TREE IN TREE FORM*/
void display(NODE root,int level)
{
	int i;
	if(root==NULL)
	return;
	display(root->rlink,level+1);
	for(i=0;i<level;i++)
	printf(" ");
	printf("%d\n",root->info);
	display(root->llink,level+1);
}
/* FUNCTION TO PRINT THE TREE USING LEVEL ORDER TRAVERSAL*/
void level_order(NODE root)
{
	NODE q[MAX_QUEUE],cur;
	int front=0,rear=-1;
	q[++rear]=root;
	while(front<=rear)
	{
		cur=q[front++];
		printf("%d",cur->info);
		if(cur->llink!=NULL)
		q[++rear]=cur->llink;
		if(cur->rlink!=NULL)
		q[++rear]=cur->rlink;
	}
	printf("\n");
}
/* FUNCTION TO INSERT AN ITEM IN TO BINARY SEARCH*/
NODE insert(int item,NODE root)
{
	NODE temp;
	NODE cur;
	NODE prev;
	char direction[10];
	int i;
	MALLOC(temp,1,struct node);
	temp->info=item;
	temp->llink=temp->rlink=NULL;
	if(root==NULL)
	return temp;
	printf("Give the directions where you want to insert(Ex:LRLR)\n");
	scanf("%s",direction);
	prev=NULL;
	cur=root;
	for(i=0;i<strlen(direction);i++)
	{
		if(cur==NULL)
		break;
		prev=cur;
		if(direction[i]=='L')
		cur=cur->llink;
		else
		cur=cur->rlink;
	}
	if(cur!=NULL||i!=strlen(direction))
	{
		printf("Insertion not possible\n");
		free(temp);
		return root;
	}
	if(direction[i-1]=='L')
	prev->llink=temp;
	else
	prev->rlink=temp;
	return root;
}

void main()
{
	NODE root=NULL;
	int choice,item;
	clrscr();
	for(;;)
	{
		printf("1:Insert	2:preorder\n");
		printf("3:postorder	4:inorder\n");
		printf("5:level order	6:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the item to be inserted\n");
			scanf("%d",&item);
			fflush(stdin);
			root=insert(item,root);
			break;
			case 2:
			if(root==NULL)
			printf("Tree is empty\n");
			else
			{
				printf("The given tree is\n");
				display(root,1);
				printf("preorder traversal is\n");
				preorder(root);
				printf("\n");
			}
			break;
			case 3:
			if(root==NULL)
			printf("Tree is empty\n");
			else
			{
				printf("The given tree is\n");
				display(root,1);
				printf("postorder traversal is\n");
				postorder(root);
				printf("\n");
			}
			break;
			case 4:
			if(root==NULL)
			printf("Tree is empty\n");
			else
			{
				printf("The given tree is\n");
				display(root,1);
				printf("inorder traversal is\n");
				inorder(root);
				printf("\n");
			}
			break;
			case 5:
			if(root==NULL)
			printf("Tree is empty\n");
			else
			{
				printf("The given tree is\n");
				display(root,1);
				printf("level order traversal is\n");
				level_order(root);
				printf("\n");
			}
			break;
			default:exit(0);
		}
	}
}




