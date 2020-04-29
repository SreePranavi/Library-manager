#include<stdio.h>
#include"inter.h"
void main()
{
int choice, uchoice;

printf("\t \t \t \t *LIBRARY NAME* \n 1.ADMIN \t \t \t 2.USER \n Enter your choice: ");
scanf("%d",&choice);

if(choice==1)
{
printf("Navigating to admin login.\n");
admin_login();}

else if(choice==2)
{{
printf("1.SIGNUP \t \t \t 2.LOGIN \n Enter your choice: ");
scanf("%d",&uchoice);
}
if(uchoice==1)
{
printf("Navigating to user signup.\n");
user_signup();
}
else if(uchoice==2)
{
printf("Navigating to user login.\n");
user_login();}

else
printf("Invalid input");
}

else
printf("Invalid input");
}
