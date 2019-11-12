#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct book
{
	int code;
	char name[20];
	char category[5];
	char date[10];
	int cost;
}b;

int seat = 60 ;

void delay(int msec);
void viewAll(); // for view all data 
void find(); // for finding data
void book_ticket(); //for booking tickets

void main()
{
	int prompt;
 	do
	{
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n");	
		printf("\t Moive Ticket booking ");
		printf("\n");
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
   		printf("\nEnter >1< To View All Movie");
		printf("\nEnter >2< To Find Movie ");
		printf("\nEnter >3< To Book Tickets");
   		printf("\nEnter >4< To Exit ");

	   	printf("\nPrompt:\t");
   		scanf("%d",&prompt); 
		system("cls");
		int t=5;

   		switch (prompt)
   		{	
		   	case 1 :
    			viewAll();
   				break;
    		
			case 2 :
    			find();
   				break;

			case 3 :
				book_ticket();
				break;
		
			case 4:
				while(t!=-1)
				{
					printf("Exiting in %d secs",t);
					t--;
					delay(1000);
					system("cls");
				}
		   		exit(0);
    			break;

    		default:
    			printf("Wrong choice !");
    			break;
   		}
	}while(prompt!=0);
}

void find() //find details
{
	struct book b;
	FILE *fp;
	
	int ch;
	printf("Enter movie code :");
	scanf("%d",&ch);

	fp = fopen("data.txt","r+");
	if(fp == NULL)
	{
		printf("file does not found !");
	}
	else
	{	
		while(fgetc(fp) != EOF)
		{
			fscanf(fp," %d %s %s %s %d",&b.code,b.name,b.category,b.date,&b.cost);
			if(b.code==ch)
			{	
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%d",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tMovie Category ::%s",b.category);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d",b.cost);
				//break;
			}
		}
	}

	fclose(fp);
}
void viewAll()
{
	
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	
	fclose(fp);

}
//for ticket booking 
void book_ticket()
{
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,total_amount;
	long int mobile;
	char name[200];

	
	char ch; //used in display all movies
	int movie_code; //for searching

	// disply all moives by default for movie code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
	
	//display ends
	printf("\n To Book ticket Choose Movie\n");
	printf("\n Enter movie code :");
	scanf("%d",&movie_code);
	//system("cls");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");

	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%d %s %s %s %d",&b.code,b.name,b.category,b.date,&b.cost);
			if(b.code==movie_code)
			{	
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%d",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tMovie category ::%s",b.category);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}
	}
	printf("\n* Fill Details  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%ld",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);
	
	
	total_amount = b.cost * total_seat;
	
	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %ld",mobile);
	printf("\n\t\tmovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	
	
	
	ufp=fopen("oldTransection.txt","a");
	
	fprintf(ufp," %s %ld %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
	printf("\n Record insert Sucessfull to the old record file");
	
	printf("\n");
	fclose(ufp);
	fclose(fp);

}

void delay(int msec)
{
	clock_t start_time=clock();
	while(clock()< start_time+msec)
		;
}
