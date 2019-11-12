#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void delay(int msec);

struct guest
{
	char name[200];
	long int mobile;
	int seat,amount,cost;
	char movie[200];
}g;

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
	{
	
    	printf("\n  ++++++++++++++++++++++++++++++  LOGIN FIRST  ++++++++++++++++++++++++++++++  ");
    	printf(" \n\n                  ENTER USERNAME:-");
		scanf("%s", &uname); 
		printf(" \n\n                  ENTER PASSWORD:-");
		while(i<10)
		{
	    	pword[i]=getch();
	    	c=pword[i];
	    	if(c==13) break;
	    	else printf("*");
	    	i++;
		}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
	if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
		printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		getch();//holds the screen
		break;
	}	
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
	
		getch();//holds the screen
	
		}
	}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
			
		getch();
		
	}
	system("cls");
		
}


struct book
{
	int code;
	char name[200];
	char category[5];
	char date[10];
	int cost;
}b;

int seat = 60 ;

void insert_details();//for inserting movie details

void old_record(); //for view old recorrds of users,booked tickets

void insert_details()
{
	
	FILE *fp;
	struct book b;
	fp=fopen("data.txt","a+");
	printf("Enter movie code :- ");	
	scanf("%d",&b.code);
	printf("Enter  name :- ");	
	scanf("%s",&b.name);
	printf("Enter Category :- ");
	scanf("%s",b.category);
	printf("Enter Release Date:- ");	
	scanf("%s",b.date);
	printf("Enter Ticket Price:- ");	
	scanf("%d",&b.cost);
	
	fp=fopen("data.txt","a+");

	if(fp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(fp," %d %s %s %s %d \n",b.code,b.name,b.category,b.date,b.cost);
		printf("Recorded Successfully");
	}
	printf("\n");
	fclose(fp);
	system("cls");
}

void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");
	
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		while(getc(fp)!=EOF)
		{
			fscanf(fp,"%s %ld %d %d %s %d \n",g.name,&g.mobile,&g.seat,&g.cost,g.movie,&g.amount);
			printf("Guest Name:: %s\nGuest Ph No:: %ld\nBooked Tickets:: %d\nCost/Seat:: %d\nMovie name:: %s\nTotal amount paid:: %d\n",g.name,g.mobile,g.seat,g.amount,g.movie,g.cost);
		}
	fclose(fp);
	}

}


void main()
{
	int t=5;
	printf("Administrator Access");
	login();
	int prompt;
	do
	{
		printf("\nEnter >1< To Insert Movie");
		printf("\nEnter >2< To View All Transactions");
   		printf("\nEnter >3< To Exit ");
   		printf("\nPrompt:\t");
   		scanf("%d",&prompt);
   		system("cls");
    	
    	switch(prompt)
    	{
    		case 1 :
    			insert_details();
    			break;
    		case 2 :
    			old_record();
    			break;
    		case 3 :
    			while(t!=-1)
    			{
    				printf("Exiting in %d secs",t);
    				t--;
    				delay(1000);
    				system("cls");
				}
    			exit(0);
    			break;
    		default :
    			printf("Wrong choice");
    			break;
		}
	}while(prompt!=0);
}

void delay(int msec)
{
	clock_t start_time=clock();
	while(clock()< start_time+msec)
		;
}
