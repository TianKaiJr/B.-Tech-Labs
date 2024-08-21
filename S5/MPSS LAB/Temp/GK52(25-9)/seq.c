#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void seq()
{
	int fileblocks[MAX];
	for(int i=0;i<MAX;i++)	//initialise all index = 0
		fileblocks[i]=0;
	
	char fname[10];
	int startB,flen,flag,ch;
	
	new:
	flag=0;
	
	printf("[FileName] >> ");
	scanf("%s",fname);
	printf("[Starting Block] >> ");
	scanf("%d",&startB);
	printf("[Length] >> ");
	scanf("%d",&flen);
	
	for(int i=startB;i<(startB+flen);i++)	//to check  the requested blocks are empty
	{
		if(fileblocks[i]==0)
			flag++;
	}
	
	if(flag==flen)		//if the req blocks are empty
	{
		printf("File Name	StartBlock	Length	BlocksOccupied\n");
		printf("   %s              %d             %d        ",fname,startB,flen);
		for(int i=startB;i<(startB+flen);i++)		// making the allocated index = 1 
		{
			if(fileblocks[i]==0)
			{
				fileblocks[i]=1;
				printf("%d  ",i);
			}
			else
				printf("Seq Block Occupied\n");
		}
		printf("\n");
		
	}
	else	//if flag != length of the file
	{
		printf("Sequential Blocks are OCCUPIED\n");
	}
	
	printf("\nInsert Another File [Yes0/No1] >> ");
	scanf("%d",&ch);
	if(ch==0)
		goto new;
	else if(ch==1) 
		exit(0);
	else
		printf("Wrong Input\n");
	
		
}

void main()
{
	seq();
}
