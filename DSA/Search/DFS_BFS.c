#include<stdio.h>
#include<stdlib.h>
void bfs(int v);
void dfs(int v);
int a[50][50],n,visited[50];
int q[20],front=-1,rear=-1;
int s[20],top=-1,count=0;
void creategraph()
{
	int i,j;
	printf("Enter The number of vertices in graph\n");
	scanf("%d",&n);
	printf("Enter the adjacency of matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
}
void bfs(int v)
{
	int i,cur;
	visited[v]=1;
	q[++rear]=v;
	printf("Nodes reachable from starting vertex %d are:\n",v);
	while(front!=rear)
	{
		cur=q[++front];
		for(i=1;i<=n;i++)
		{
			if((a[cur][i]==1)&&(visited[i]==0))
			{
				q[++rear]=i;
				visited[i]=1;
				printf("%d",i);
			}
		}
	}
}
void dfs(int v)
{
	int i;
	visited[v]=1;
	s[++top]=v;
	for(i=1;i<=n;i++)
	{
		if((a[v][i]==1)&&(visited[i]==0))
		{
			dfs(i);
			count++;
		}
	}
}
int main()
{
	int ch,start,i,j;
	creategraph();
	printf("\n\n~~~ MENU~~~~");
	printf("1:BSF:Print all nodes reachable from a given starting node\n");
	printf("2:DSF:Print all nodes reachable from a given starting node\n");
	printf("3:Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:for(i=1;i<=n;i++)
		visited[i]=0;
		printf("Enter the starting vertex\n");
		scanf("%d",&start);
		bfs(start);
		for(i=1;i<=n;i++)
		{
			if(visited[i]==0)
			printf("\n The vertex that is not reachable is %d",i);
		}
		break;
		case 2:for(i=1;i<=n;i++)
		visited[i]=0;
		printf("\n Enter the starting vertex:\t");
		scanf("%d",&start);
		dfs(start);
		printf("\n Nodes reachable from starting vertex %d are:\n",start);
		for(i=1;i<=count;i++)
		printf("%d\t",s[i]);
		break;
		case 3:exit(0);
		default:printf("\n Please Enter valid choice:");
	}
		return 0;
}
