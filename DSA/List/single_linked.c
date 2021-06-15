#include<stdio.h>
#include<stdlib.h>
struct node
{
 int info;
 struct node*link;
};
typedef struct node*NODE;
#define MALLOC(p,n,type)\
p=(int*)malloc(n*sizeof(int));\
if(p==NULL)			\
{				  \
printf("Insufficient memory\n");    \
exit(0);			       \
}
void display(NODE first)
{
 NODE temp;
 if(first==NULL)
 {
  printf("list is empty\n");
  return;
 }
 printf("The content of singly linked list\n");
 temp=first;
 while(temp!=NULL)
 {
  printf("%d\n",temp->info);
  temp=temp->link;
 }
 printf("\n");
}
NODE delete_front(NODE first)
{
 NODE temp;
 if(first==NULL)
 {
   printf("list is empty can not delete\n");
   return first;
 }
 temp=first;
 temp=temp->link;
 printf("item deleted=%d\n",first->info);
 free(first);
 return temp;
}
NODE insert_rear(int item,NODE first)
{
  NODE temp;
  NODE cur;
  MALLOC(temp,1,struct node);
  temp->info=item;
  temp->link=NULL;
  if(first==NULL)
  return temp;
  cur=first;
  while(cur->link!=NULL)
  {
   cur=cur->link;
  }
  cur->link=temp;
  return first;
}

void main()
{
   NODE first=NULL;
   int choice,item;
   clrscr();
   for(;;)
   {
     printf("1:Insert rear 2: Delete front 3: Display 4: exit\n");
     printf("Enter your choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
      case 1:printf("Enter the item to be inserted\n");
      scanf("%d",&item);
      first=insert_rear(item,first);
      break;
      case 2:first=delete_front(first);
      break;
      case 3:
      display(first);
      break;
      default:
      exit(0);
     }
   }
}
