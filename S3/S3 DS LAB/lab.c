#include<stdio.h>

struct term
{
	int coef,exp;
}p1[10],t,result[10];

void main()
{
	int limit,i;
	printf("Enter the number of terms = ");
	scanf("%d",&limit);
	
	printf("Enter the POLYNOMIAL\n");
	for(i=0;i<limit;i++)
	{
		printf("POLYNOMIAL %d Coefficent >> ",i+1);
		scanf("%d",&p1[i].coef);
		printf("POLYNOMIAL %d Exponent >> ",i+1);
		scanf("%d",&p1[i].exp);
	}
	
	printf("Enter the TERM for Multiplication\n");
	printf("TERM Coefficent >> ");
	scanf("%d",&t.coef);
	printf("TERM Exponent >> ");
	scanf("%d",&t.exp);
	
	for(i=0;i<limit;i++)
	{
		result[i].coef=p1[i].coef * t.coef;
		result[i].exp=p1[i].exp + t.exp;
	}
	
	printf("Given Polynomial >>");
	for(i=0;i<limit-1;i++)
	{
		printf(" %dx^%d +",p1[i].coef,p1[i].exp);
	}
	printf(" %dx^%d\n",p1[i].coef,p1[i].exp);
	
	printf("Given Term >>");
	printf(" %dx^%d \n",t.coef,t.exp);

	
	printf("Resultant Polynomial >>");
	for(i=0;i<limit-1;i++)
	{
		printf(" %dx^%d +",result[i].coef,result[i].exp);
	}
	printf(" %dx^%d\n",result[i].coef,result[i].exp);
	
}







