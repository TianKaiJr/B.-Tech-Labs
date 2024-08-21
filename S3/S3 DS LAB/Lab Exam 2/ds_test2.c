#include<stdio.h>
#include<stdlib.h>

struct node
{
	int elem;
	struct node *link;
}*head=NULL,*ptr,*prev,*pptr;

int h=0,hcount=0;

struct node* newNode(int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->elem=data;
	new->link=NULL;
	return new;
}
void insertE(int data)
{
	struct node *new=newNode(data);
	if(head==NULL)
		head=new;
	else
	{
		ptr=head;
		while(ptr->link != NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
	}
}

void display()
{
	if(head==NULL)
		printf("Empty List !!\n");
	else
	{
		pptr=head;
		while(pptr != NULL)
		{
			printf("%d | ",pptr->elem);
			pptr=pptr->link;
		}
		printf("\b\n");
	}
}
void frequency()
{
	struct node *fptr;
	int f,count=0;
	if(head==NULL)
		printf("Empty List !!\n");
	else
	{
		printf("Frequency Key = ");
		scanf("%d",&f);
		fptr=head;
		while(fptr != NULL)
		{
			if(fptr->elem == f)
			{
				count++;
			}
			fptr=fptr->link;
		}
		printf("Frequency of '%d' is '%d'\n",f,count);
		
		if(count > hcount)
		{
			h=f;
			hcount=count;
		}	
	}
}
void deleteP()
{
	int pos=h;
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        int i;
        for(i=1;i<=hcount;i++)
        {
        	ptr = head;
        	while(ptr != NULL && ptr -> elem != pos)
        	{
        	    prev = ptr;
        	    ptr = ptr -> link;
        	}
        	if (ptr == NULL)
        	{
        	    printf("Element Not Found\n");
        	}
        	else
        	{
        	    if (head -> elem == pos)
        	    {
        	        ptr = head;
        			head = ptr -> link;
        			free(ptr);
        	    }
        	    else
        	    {
        	        prev -> link = ptr -> link;
        	        free(ptr);
        	    }
        	}
        }
    }
}

int get()
{
	printf("Enter the element = ");
	int n;
	scanf("%d",&n);
	return n;
}
void main()
{
	start:
	printf("\n    MENU\n");
	printf("1.Insert End\n");
	printf("2.Display\n");
	printf("3.Frequency of Key Element\n");
	printf("4.Delete Highest Frequency Element\n");
	printf("0.Exit\n");
	printf("Choice >>> ");
	
	int ch;
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:insertE(get());
			break;
		case 2:display();
			break;
		case 3:frequency();
			break;
		case 4:deleteP();
			break;
		case 0:exit(0);
			break;
		default:printf("Wrong Input\n");
	}
	goto start;
}


/*
if(fptr->elem != NULL)
			{
				for(i=0;i<25;i++)
				{
					if(fptr->elem != farr[i])
					{
						
					}
			}
*/
