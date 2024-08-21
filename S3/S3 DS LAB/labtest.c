#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*head=NULL,*ptr,*temp;



void insert()
{
	//struct node *ptr;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		printf("Enter the value = ");
		scanf("%d",&item);
		ptr->data=item;
		ptr->link=head;
		head=ptr;
	}
	printf("\n");
	//printf("PTR = %d",ptr->data);
}

void move()
{
	struct node *front;
	front=head;
	while(front->link != NULL)
	{
		front=front->link;
	}
	
	/*if(front != NULL)
	{
		printf("LIST EMPTY\n");
	}
	else
	{*/
		//temp=ptr;
		
	if(front->link == NULL)
	{	
		front->link=head;
		head=ptr->link;
		ptr->link=NULL;
	}
	//}	
	printf("\n");
}

void display()
{
	struct node *ptr1;
	ptr1=head;
	printf("Elements of List = ");
	while(ptr1 != NULL)
	{
		
		printf("%d  ",ptr1->data);
		ptr1=ptr1->link;
	}
	printf("\n\n");
}

void main()
{
	start:
	printf("### MENU ###\n");
	printf("1.Insert To Front\n");
	printf("2.Display\n");
	printf("3.Move from Front to Rear\n");
	printf("4.Exit\n");
	printf("Enter the Choice [1/2/3/4] = ");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert();
			break;
		case 2:display();
			break;
		case 3:move();
			break;
		case 4:exit(0);
			break;
		default:printf("Wrong Input\n");
	}
	goto start;
}










