#include<stdio.h>
#include<stdlib.h>

int *array;

void main()
{
	int n;
	printf("Enter the number of elements:\t");
	scanf("%d",&n);
	array=(int*)calloc((n+1),sizeof(int));

	int i;

	for(i=1;i<(n);i++)
	{
		printf("Enter the element [%d]:\t\a",i);
		scanf("%d",(array+i));
	}

	printf("All the elements are entered\n");

	array=0;

	for(i=0;i<n+1;i++)
	{
		printf("Array[%d]=%d\n",i,*(array+i));
	}

}
