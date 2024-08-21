#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int files[MAX];
struct indarr
{
	int fname;
	struct node *shead;
}p[MAX];

struct node
{
	int *address;
	int index;
	struct node *link;
};

// void file()
// {
// 	for(int i=0;i<MAX;i++)
// 	{
// 		if(i%5==0)
// 		{
// 			printf("\n");
// 			printf("|||| I:%2d V:%2d ||||   ",i,files[i]);

// 		}
// 		else
// 			printf("|||| I:%2d V:%2d ||||",i,files[i]);
// 	}
// 	printf("\n");
// }

void main()
{
	for(int i=0;i<MAX;i++)
		files[i]=NULL;
		
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
	
	if(files[ibk]!=NULL)
	{
		printf("Index Block Occupied\n");
		goto x;
	}
	else
	{
		files[ibk]=88;
	}
	
	struct node *head=NULL;

	for(int i=0;i<flen;i++)
	{
		y:
		printf("Enter the (%dth/%d) Block = ",i+1,flen);
		scanf("%d",&temp);
		if(files[temp]!=NULL)
		{
			printf("Block(%d) Occupied\n",temp);
			goto y;
		}
		else
		{	
			files[temp]=fnam;
			p[ibk].fname=fnam;
			struct node *new=(struct node *)malloc(sizeof(struct node));
			new->address=&files[temp];
			new->index=temp;
			new->link=NULL;
			struct node *ptr=head;;
			if(head==NULL)
			{
				head=new;
				p[ibk].shead=new;
			}
			else
			{
				while(ptr->link!=NULL)
					ptr=ptr->link;
				ptr->link=new;
			}
			p[ibk].arr[i]=temp;
		}
	}
	// file();
	printf("\nFILE :- %d\tIndex Block :- %d\t",p[ibk].fname,ibk);
	printf("Block (Index -> Value) :- ");
	struct node *ptr2=p[ibk].shead;
	if(head==NULL)
		printf("Empty List\n");
	else
	{
		while(ptr2!=NULL)
		{
			int tmp=*(ptr2->address);
			printf("%d->%d , ",ptr2->index,tmp);
			ptr2=ptr2->link;
		}
	}
	
	printf("\nDo want to continue ? [no0/yes1] = ");
	scanf("%d",&ch);
	if(ch)
		goto new;
	else
		exit(0);
		
}
