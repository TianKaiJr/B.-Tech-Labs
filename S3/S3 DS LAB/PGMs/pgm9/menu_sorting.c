#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int array[MAX],limit;

void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

void inputarr()
{	
	int i;
	printf("Enter the limit of the array = ");
	scanf("%d",&limit);
	printf("Enter the elements of array\n");
	for(i=0;i<limit;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Inputted array = ");
	for(i=0;i<limit;i++)
	{
		printf("%d  ",array[i]);
	}
	printf("\n");
}

void outputarr()
{	
	int i;
	printf("Sorted Array = ");
	for(i=0;i<limit;i++)
	{
		printf("%d  ",array[i]);
	}
	printf("\n");
}

void insertion()
{
	inputarr();
	int i,j;
	for(i=1;i<limit;i++)
		for(j=i ; (array[j] < array[j-1] ) && j>0 ;j--)
		{
			swap(&array[j],&array[j-1]);
		}
	outputarr();
}

void selection()
{
	inputarr();
	int i,j,min;
	for(i=0;i<limit-1;i++)
	{
		min=i;
		for(j=i+1;j<limit;j++)
		{
			if(array[j]<array[min])
			{
				min=j;                                                                                            
			}
			if(min != i)
			{
				swap(&array[min],&array[i]);
			}
		}
	}
	outputarr();
}
void main()
{
	start:
	printf("\n### MENU ###\n");
	printf("1.Insertion Sorting\n");
	printf("2.Selection Sorting\n");
	printf("3.Exit\n");
	printf("Enter the Choice = ");
	int ch;
	scanf("%d",&ch);
	printf("\n");
	
	switch(ch)
	{
		case 1:insertion();
			break;	
		case 2:selection();
			break;
		case 3:exit(0);
			break;
		default:printf("Wrong Input\n");
	}
	goto start;
	
}
