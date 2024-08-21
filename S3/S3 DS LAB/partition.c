#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *nhead=NULL,*ptr,*ptr2,*gte,*current;

int x;

void display(struct node *head)
{
	ptr=head;
	printf("List >> [");
	while(ptr!=NULL)
	{
		printf("%d  ",ptr->data);
		ptr=ptr->link;
	}
	printf("\b\b]\n");
}


void insertE(struct node **head)
{
	int val;
	printf("Enter The Element >> ");
	scanf("%d",&val);
	
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=val;
	new->link=NULL;
	
	if(*head==NULL)
		*head=new;
	else
	{
		ptr=*head;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=new;
	}
	display(*head);
}

void sort()
{
	int temp;
	ptr=nhead;
	ptr2=nhead->link;
	while(ptr!=NULL)
	{
		ptr2=ptr->link;
		while(ptr2!=NULL)
		{
			if(ptr->data > ptr2->data)
			{  
                       	temp=ptr->data;  
                       	ptr->data=ptr2->data;  
                       	ptr2->data=temp;
                       }
			ptr2=ptr2->link;
		}
		ptr=ptr->link;
	}
	printf("Sorted ");
	display(nhead);
}

void partition()
{
	sort();
	printf("Value of 'X' >> ");
	scanf("%d",&x);
	
	ptr=nhead;
	while(ptr->data!=x)
	{
		current=ptr;
		ptr=ptr->link;
	}
	
	if(ptr->data==x)
	{
		gte=ptr;
		current->link=NULL;
		printf("Less Than X >> ");
		display(nhead);
		printf("Greater Than or Equal to X >> ");
		display(gte);
	}
	else
		printf("Partition Not Possible\n");
}

void main()
{
	int ch;
	START:
	printf("-------------------------\n");
	printf("       MENU\n");
	printf("1.Insert into LL\n");
	printf("2.Partition of LL\n");
	printf("0.Exit\n");
	printf("-------------------------\n");
	printf("Choice >> ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:insertE(&nhead);
			break;
		case 2:partition();
			break;
		case 0:exit(0);
			break;
	}
	goto START;
	
}
