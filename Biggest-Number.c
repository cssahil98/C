#include<stdio.h>
#include<math.h>
#include<conio.h>

void main()
{
 int a,b,c;
  clrscr();
   printf("enter the three numbers \n");
     scanf("%d %d %d", &a,&b,&c);
      
      if(a>b)
        {
          if(a>c)
             
		{
                  printf(" a is greater than b and c \n");
                }
                else
		{
                  printf(" c is greater than a and b \n");
                }
        }
        else
       if(b>c)
        {
         printf(" b is greater than a and c \n");
        }
        else
        {
         printf(" c is greater than a and b \n");
         }

    getch();
 } 
