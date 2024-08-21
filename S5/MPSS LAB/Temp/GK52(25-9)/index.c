#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int files[MAX];
struct indarr
{
	
	int fname;
	int arr[MAX];
}p[MAX];

void main()
{
	for(int i=0;i<MAX;i++)
		files[i]=0;
		
	int flen,ibk;
	int fnam,temp,ch;
	new:
	
	printf("Enter File Name = ");
	scanf("%d",&fnam);
	
	printf("Enter the file length = ");
	scanf("%d",&flen);
	
	x:
	printf("Enter the index block = ");
	scanf("%d",&ibk);
	
	if(files[ibk]==1)
	{
		printf("Index Block Occupied\n");
		goto x;
	}
	else
	{
		files[ibk]=1;
	}
	

	
	for(int i=0;i<flen;i++)
	{
		y:
		printf("Enter the (%dth/%d) Block = ",i+1,flen);
		scanf("%d",&temp);
		if(files[temp]==1)
		{
			printf("Block(%d) Occupied\n",temp);
			goto y;
		}
		else
		{	
			p[ibk].fname=fnam;
			p[ibk].arr[i]=temp;
			files[temp]=1;
		}
	}
	printf("FILE :- %d\tIndex Block :- %d\t",p[ibk].fname,ibk);
	printf("Block :- ");
	for(int i=0;i<flen;i++)
	{
		printf("%d ",p[ibk].arr[i]);
	}
	
	printf("\nDo want to continue ? [no0/yes1] = ");
	scanf("%d",&ch);
	if(ch)
		goto new;
	else
		exit(0);
		
}	
	
	



