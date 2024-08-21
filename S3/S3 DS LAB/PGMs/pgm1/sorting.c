/* GOPIKRISHNA V
	S3 CSE A
	52
*/

//Program with menu driven sorting 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void linear();
void binary();

void main()
{	
	int sel;
	start:
	printf("\n1.Linear Search\n2.Binary Search\n3.Exit\n");
	printf("Select the type of sorting [1/2/3]\n");
	scanf("%d",&sel);
	switch(sel)
		{
			case 1:linear();
			break;
			case 2:binary();
			break;
			case 3:exit(0);
			break;
			default:printf("Wrong Input\n");
		}
	goto start;
}

void linear()
{
	int key,arr[50],i,limit;
	printf("Enter the limit = ");
	scanf("%d",&limit);
	printf("Enter the elements\n");
	for(i=0;i<limit;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element to be searched = ");
	scanf("%d",&key);
	
	for(i=0;i<limit;i++)
	{
		if(arr[i]==key)
		{
			printf("The element found at %d\n\n\n",i+1);
		}
	}
}
void binary()
{
	int key,arr[50],i,limit;
	printf("Enter the limit = ");
	scanf("%d",&limit);
	printf("Enter the elements\n");
	for(i=0;i<limit;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element to be searched = ");
	scanf("%d",&key);
	
	for (int c=0;c<limit-1;c++)
	{
    		for(int d=0;d<limit-c-1;d++)
    		{
    			if(arr[d]>arr[d+1]) 
			{
        			int temp=arr[d];
        			arr[d]=arr[d+1];
        			arr[d+1]=temp;
     			}
    		}
 	}
 	
 	printf("The sorted array [Ascending]\n");
 	
 	for(int k=0;k<limit;k++)
 	{
 		printf(" %d \t",arr[k]);
	}
	
	int low,mid,high;
	low=0;
	high=limit-1;
	mid=(low+high)/2;
	
	int flag=0;
	while(flag==0)
	{
		if(arr[mid]==key)
		{
			printf("\nThe element found at %d\n\n\n",mid+1);
			flag=1;
		}
		if(key>arr[mid])
		{
			low=mid+1;
			high=limit-1;
			mid=(low+high)/2;
		}
		if(key<arr[mid])
		{
			low=0;
			high=mid-1;
			mid=(low+high)/2;
		}
	}
}	
