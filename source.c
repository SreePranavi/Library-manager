
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"inter.h"

int search();
int pattern_match(char *, int , char *, int);
int search()
{
int n,x,i;
FILE *fh,*fh2,*fh3;
char classic_books[166];
char fiction_books[166];
char adventure_books[166];

fh=fopen("classic_bks.txt","r");
fread(&classic_books,166,1,fh);
fh2=fopen("fiction.txt","r");
fread(&fiction_books,166,1,fh2);
fh3=fopen("adventure.txt","r");
fread(&adventure_books,166,1,fh3);

char genre[100];
char bk_search[100];
char s;
int res=-1;
int cblen=strlen(classic_books);
int fblen=strlen(fiction_books);
int ablen=strlen(adventure_books);

printf("enter the genre\n");   
printf("1.classics\n2.fiction\n3.adventure\n");
scanf("%d",&n);

fflush(stdin);

printf("The option entered is %d\n", n);
printf("Enter the book to be searched\n");
scanf("%[^\n]",bk_search);
printf("the book is %s\n",bk_search);

int bkslen=strlen(bk_search);
		
printf("The name of the book to be serched %s\n",bk_search);

switch(n)
{
	case 1: 
		res= pattern_match(classic_books,cblen,bk_search,bkslen);
		if (res!=-1)
		{
			printf("the entered book %s is found in the library!",bk_search);
			break;
		}
	case 2:
		res= pattern_match(fiction_books,fblen,bk_search,bkslen);
		if (res!=-1)
		{
			printf("the entered book %s is found in the library!",bk_search);
			break;
		}
	case 3:
		res= pattern_match(adventure_books,ablen,bk_search,bkslen);
		if (res!=-1)
		{
			printf("the entered book %s is found in the library!",bk_search);
			break;
		}
		default:printf("not found");
		break;	
		
}
	
fclose(fh);
fclose(fh2);
fclose(fh3);

return 0;
}

int pattern_match(char *text, int n, char *pattern, int m) 
{
	int i; int j; 
	int res=-1 ; 
	
	for(i=0; i<=(n-m);i++)  
	{
		for(j=0;j<m && pattern[j] == text[i+j]; j++);  
		if(j >= m)    
			res = i;  
	} 
	return res; 
}

int count(int n)
{
int cnt=0;
while(n)
{n=n/10;
cnt++;
}return cnt;
}

int id_generator(int mem)
{
int id;
int idn1=1000,idn2=2000,idn3=3000;
switch(mem)
{
	
			id=++idn1;
			break;
	case 2:
			
			id=++idn2;
			break;
	case 3:
			
			id=++idn3;
			break;
					
}
printf("Your login id is:%d",id);
return id;
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
{printf("Invalid");pin_verify();
}return p;
}

int phone_verify()
{
long int phone;

printf("Enter contact number:");
scanf("%ld",&phone);

int dn=count(phone);

if(dn==10)
printf(" ");

else
{printf("Invalid");
return phone_verify();}	

return phone;
}

int membership_verify()
{int membership,idr;

printf("\n Availabe membership options:\n 1.Premium \n 2.Student \n 3.Null\n");
scanf("%u",&membership);

if(membership==1 || membership==2 || membership==3)
printf(" ");

else
{printf("Invalid");membership_verify();}

idr=id_generator(membership);
}

void read(char buff[])
{char *token =strtok(buff,",");
int counter=0;

while(token!=NULL)
{counter++;printf("%s\n",token);
token=strtok(NULL,",");
}}

void user_signup()
{
char address[400],membership,mail[100];

int age;
char name[100],gender[3];

FILE *fp=fopen("userdet.csv","ab+");
FILE *afp=fopen("auserdet.csv","ab+");
	
printf("Enter the name:");
scanf("%s",name);

printf("Enter the gender F/M:");
scanf("%s",gender);

printf("Enter the age:");
scanf("%d",&age);

printf("Enter the address:");
scanf("%s",address);

printf("Enter email id:");
scanf("%s",mail);

long int phone=phone_verify();
int id=membership_verify();
int pin=pin_verify();

fprintf(fp,"\n%d%,%s,%d,%s,%ld,%s,%s,%d",id,name,age,gender,phone,mail,address,pin);
fprintf(afp,"\n%d%,%s,%d,%s,%ld,%s,%s",id,name,age,gender,phone,mail,address);

fclose(fp);
fclose(afp);
}   

void user_login()
{
int ans,o;
char*token;
char request[200],n[50];

printf("Enter name:");
scanf("%s",n);

FILE *afp=fopen("userdet.csv","r");

char ch[100];int i=0;

while(fgets(ch,100,afp)!=NULL)
{int c=1 ;char*id;
token=strtok(ch,",");

while(token!=NULL && c<2)
{token=strtok(NULL,",");
c++;
}

if(strcmp(token,"Name")==0)
printf("Logged in.");
printf("1.search 2.Request a book.");
scanf("%d",&o);

if(o==1)
search();

if(o==2)
{
FILE*fnu=fopen("Notifications.txt","ab+");
scanf("%s",request);
fprintf(fnu,"\n%s",request);
fclose(fnu);
fclose(afp);
}}}

void admin_login()
{
char Notifications[1000];int inp;

printf("Enter the pin:");
scanf("%d",&inp);

int apin=8888,opt;

if(inp==apin)
{printf("You have successfully logged in.");
printf("1.User accounts \n2.Books\n3.Notifications");
scanf("%d",&opt);

if(opt==1)
{
FILE*auser=fopen("auserdet.csv","r");
int count=0;
do{
	char buff[1024];
	fgets(buff, 1024, (FILE*)auser);
	count++;
	if(count!=1)
	{printf(buff);read(buff);}
}while((getc(auser))!=EOF);

fclose(auser);
}

else if(opt==2)
{int gen;
FILE *f1,*f2,*f3;
char classic_books[166],fiction_books[166],adventure_books[166];

printf("Choose the genre:");
scanf("%d",&gen);

if(gen==1)
{f1=fopen("classic_bks.txt","r");
fread(&classic_books,166,1,f1);
printf("%s",classic_books);
fclose(f1);}

else if(gen==2)
{f2=fopen("fiction.txt","r");
fread(&fiction_books,166,1,f2);
printf("%s",fiction_books);
fclose(f2);}

else if(gen==3)
{f3=fopen("adventure.txt","r");
fread(&adventure_books,166,1,f3);
printf("%s",adventure_books);
fclose(f3);}

else
printf("Invalid");
}

else if(opt==3)
{FILE*fna=fopen("Notifications.txt","r");
fread(&Notifications,1000,1,fna);
printf("%s",Notifications);
fclose(fna);
}
}

else
printf("\a TERMINATED");
}
