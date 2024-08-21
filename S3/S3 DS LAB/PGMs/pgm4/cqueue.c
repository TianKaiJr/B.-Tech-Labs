/* GOPIKRISHNA V
	S3 CSE A
	52
	
	C PROGRAM TO PERFORM OPERATIONS ON A CIRCULAR QUEUE 
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int items[SIZE];
int front = -1, rear = -1;

int isFull() 
{
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) 
  	return 1;
  else
  	return 0;
}

int isEmpty() 
{
  if(front == -1) 
  	return 1;
  else
  	return 0;
}

void enQueue() 
{	
	int element;
	printf("Enter the element = ");
 	scanf("%d",&element);
 	
  	if ((front == -1) && (rear == -1))
  	{
  	 	front=0;
  	 	rear=0;
  	 	items[rear]=element;
  	}
  	else
  	{
  	 	if(front==(rear+1)%SIZE)
  	 		printf("\nQUEUE FULL\n");
  	 	else
  	 	{
  	 		rear=(rear+1)%SIZE;
  	 		items[rear]=element;
  	 	}
  	}
  	printf("%d -- INSERTED\n",element);
}

void deQueue() 
{
	int element;
	if(front == -1 && rear == -1)
		printf("\nQUEUE EMPTY\n");
	else
	{
		if(front==rear)
		{
			element=items[front];
			front=-1;
			rear=-1;
		}
		else
		{
			element=items[front];
			front=(front+1)%SIZE;
		}
	}
	
	printf("%d -- DELETED\n",element);
}

void display() 
{
	int i;
	if (isEmpty())
		printf(" \nQUEUE EMPTY\n");
	else 
	{
    		printf("\n Items = ");
    		for (i = front; i != rear+1; i = (i + 1) % SIZE)
      			printf("%d\t", items[i]);
      	printf("\n");
	}
}

void main() 
{	
    int sel;
    start:
    printf("\n\n\n### MENU ###\n");
    printf("1.EnQueue\n");
    printf("2.DeQueue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Select the Operation [1/2/3/4] = ");
    scanf("%d",&sel);
    switch(sel)
    {
    	case 1:enQueue();
    		break;
    	case 2:deQueue();
    		break;
    	case 3:display();
    		break;
    	case 4:exit(0);
    		break;
    	default:printf("Wrong Input\n");
    }
    goto start;
    
}




