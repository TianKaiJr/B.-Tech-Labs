#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

char stack[MAX];
char postfix[MAX],infix[MAX];
int top=-1;

// push operation
void push(char c)
{
	if (top=MAX-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		top++;
		stack[top]=c;
	}
}
//pop operation
char pop()
{	
	char c;
	if(top==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{	
		c=stack[top];
		top--;
	}
	return c;
}
int bspace(char c) // bspace detection
{
	if ((c=" ") || (c="	"))
		return 1;
	else 
		return 0;
}

void print() // print postfix
{
	int i=0;
	printf("Postfix Form : ");
	while(postfix[i]!="\0")
		printf("%c ",postfix[i++]);
	printf("\n");
}		
	
int priority(char symbol) // operator priority check
{
	switch (symbol)
	{
		case '^':return 3;
			break;
		case '*':return 2;
			break;
		case '/':return 2;
			break;
		case '-':return 1;
			break;
		case '+':return 1;
			break;
		default:return 0;
	}
}

int isempty() // stack empty check
{
	if(top==-1)
		return 1;
	else
		return 0;
}
// to postfix function
void topostfix()
{
	int i,j=0;
	char next,symbol;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(bspace(symbol) != 1)
		{
			switch(symbol)
			{
				case '(' :
					push(symbol);
					break;
				
				case ')' :
					while((next=pop()) != '(')
					{
						postfix[j]=next;
						j++;
					}
					break;
					
				case '+':if ((isempty() == 0) && ( priority(stack[top]) >= priority(symbol)))
					{
						postfix[j++]=pop();
						push(symbol);
					}
					break;
					
				case '-':if ((isempty() == 0) && ( priority(stack[top]) >= priority(symbol)))
					{
						postfix[j++]=pop();
						push(symbol);
					}
					break;
					
				case '*':if ((isempty() == 0) && ( priority(stack[top]) >= priority(symbol)))
					{
						postfix[j++]=pop();
						push(symbol);
					}
					break;
					
				case '/':if ((isempty() == 0) && ( priority(stack[top]) >= priority(symbol)))
					{
						postfix[j++]=pop();
						push(symbol);
					}
					break;
					
				case '^':if ((isempty() == 0) && ( priority(stack[top]) >= priority(symbol)))
					{
						postfix[j++]=pop();
						push(symbol);
					}
					break;
	
					
				default: postfix[j++]=symbol;
			}
			while(isempty()== 0)
			{
				postfix[j++]=pop();
			}
		}
	}
	postfix[j]="\0";	
}
void main()
{
	printf("\nEnter the infix expression : " );
	gets(infix);
	
	topostfix();
	print();
}

				
						 		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
