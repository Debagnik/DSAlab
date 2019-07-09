#include<stdio.h>
#include<stdlib.h>

struct books
{
	int isbn;
	char title[80];
	char author[80];
	char publsr[80];
	float price;
};

typedef struct books record;

record *getData(int j,int n);
void displayData(record *data);

void main()
{
	int i,n;

	printf("Enter the number of entries:\t\a");
	scanf("%d",&n);
	
	record *data;
	
	for(i=1;i<n;i++)
	{
		(data+i)=getData(i,n);
	}

	for(i=1;i<n;i++)
	{
		displayData((data+i));
	}
	
}

record *getData(int j,int n)
{
	record *ptr;
	
	ptr=(record*)calloc(n,sizeof(record));
	
	printf("Enter details of book %d:\nISBN:\t",j);
	scanf("%d",&(ptr+j)->isbn);
	printf("Title:\t");
	scanf("%s",&(ptr+j)->title);
	printf("Author:\t");
	scanf("%s",&(ptr+j)->author);
	printf("Publisher:\t");
	scanf("%s",&(ptr+j)->publsr);
	printf("Price:\t");
	scanf("%f",&(ptr+j)->price);

	return(ptr);
}

void displayData(record *data)
{
	printf("Details of book %d are as follows:\nISBN:\t%d\nTitle:\t%s\nAuthor:\t%s\nPublisher:\t%s\nPrice:\t%f\n\n\n",data->isbn,data->title,data->author,data->publsr,data->price);
}

