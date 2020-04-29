#include<stdio.h>
#include"inter.h"

int count(int n)
{int cnt=0;
while(n)
{n=n/10;
cnt++;
}return cnt;}

void id_generator(int mem)
{
char idl;
int idn1=0,idn2=0,idn3=0;
switch(mem)
{
	case 1:
			idl='p';
			idn1++;
			printf("%c000%d",idl,idn1);
			break;
	case 2:
			idl='s';
			idn2++;
			printf("%c000%d",idl,idn2);
			break;
	case 3:
			idl='n';
			idn3++;
			printf("%c000%d",idl,idn3);
			break;
			
}
}

int pin_verify()
{
int pin,p,res;
printf("\nFor secuirity reasons kindly enter a 4 digit pin: ");
scanf("%d",&pin);
int dn=count(pin);
if(dn!=4)
printf("Invalid");
else
{printf("Re-enter the pin:");
scanf("%d",&p);
if(p==pin)
res=0;
else
res= -1;
}
if(res==0)
printf("You may now use the ID and pin to login.");
else if(res==-1) 
{printf("Invalid");pin_verify();}
}

void phone_verify()
{
int phone;
printf("Enter contact number:");
scanf("%d",&phone);
int dn=count(phone);
if(dn==10)
printf(" ");
else
{printf("Invalid");
return phone_verify();}	
}
void membership_verify()
{int membership; 
printf("\n Availabe membership options:\n 1.Premium \n 2.Student \n 3.Null\n");
scanf("%u",&membership);
if(membership==1 || membership==2 || membership==3)
printf(" ");
else
{printf("Invalid");membership_verify();}
id_generator(membership);}



void user_signup()
{
char name[100],address[400],gender[3],id,membership,mail;
int pin;
unsigned int phone; 
int age;
printf("Enter the name:");
scanf("%s",&name);

printf("Enter the gender F/M:");
scanf("%s",&gender);

printf("Enter the age:");
scanf("%d",&age);

printf("Enter the address:");
scanf("%s",&address);

printf("Enter email id:");
scanf("%s",&mail);

phone_verify();
membership_verify();


//printf("Your ID is: %c ",id);

pin_verify();
}


