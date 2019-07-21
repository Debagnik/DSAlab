#include<stdio.h>
#include<stdlib.h>

void main()
{
	int prev=1,next=1,temp=1;
	int i,n, *ptr;

	printf("Enter the number of elements:\t");
	scanf("%d",&n);

	int array[n];

	array[n]=(int*)calloc(n+1,sizeof(int));
	
	ptr = &array;
	for(i=0;i<n;i++)
	{
		printf("Enter element[%d]:\t\a",i);
		scanf("%d",(ptr+i));
		printf("/n Element [%d]: %d",i,(ptr+i));
	}

	for(i=0;i<n;i++)
	{
		if(i==0)
			prev=1;
		else
			prev=temp;
		if(i==2)
			next=1;
		else
		{
			next = (ptr+i+1);
			temp = (ptr+i);
			*(ptr+i) = prev*next;
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d",*(ptr+i));
	}
}


	
