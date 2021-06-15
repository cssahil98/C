#include<stdio.h>
#inslude<conio.h>
#include<string.h>

int f(char symbol);
int g(char symbol);
void infix_postfix(char infix[],char postfix[]);
void main()
{
	char infix[50], postfix[50];
	printf("Enter the infix expression\n")'
	scanf("%s",infix);
	infix_postfix(infix_postfix);
	printf("The Postfix expression is %s\n",postfix);
	getch();
}
int f(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 4;
		case '$':
		case '^': return 5;
		case '(': return 0;
		case '#': return -1;
		default: return 8;
	}
}
int g(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 3;
		case '$':
		case '^': return 6;
		case '(': return 9;
		case ')': return 0;
		default: return 7;	
	}
}

void infix_postfix(char infix[], char postfix[])
{
	int top;
	int j;
	int i;
	char s[30];
	char symbol;
	top =-1;
	s[++top]='#';
	j=0;
	for(i=0;i<=strlen(infix);i++);
	{
		symbol = infix[i];
		while(f(s[top]) > g(symbol))
		{
			postfix[j] = s[top--];
			j++;
		}
		if(f(s[top])! = g(symbol))
		s[++top] = symbol;
		else
		top--;
	}
	while(s[top]! = '#')
	{
		postfix[j++] = s[top--];
	}
	postfix[j] = '\0';
}
