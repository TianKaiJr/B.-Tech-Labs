#include<stdio.h>
struct node
{
	unsigned dist[20];
	unsigned from[20];
}rt[10];

int dmat[20][20];
int n,i,j,k,count=0;

void print_routing_table()
{
	printf("\nDistance Vector Routing Table\n");
	for(i=0;i<n;i++)
	{
		printf("\nRouter %d\n",i+1);
		printf("NODE | NEXT_HOP | DISTANCE\n");
		for(j=0;j<n;j++)
		{
			printf("%4d | %8d | %8d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
		}
	}	
	printf("\n\n");
}

int main()
{
	printf("Number of nodes >> ");
	scanf("%d",&n);
	printf("Cost Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			scanf("%d",&dmat[i][j]);
			dmat[i][i]=0;
			rt[i].dist[j]=dmat[i][j];
			rt[i].from[j]=j;
		}
	}
	do
	{	
		count=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
				{
					if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
					{
						rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
						rt[i].from[j]=k;
						count++;
					}
					print_routing_table();
				}
		// print_routing_table();
	}
	while(count!=0);
	
	printf("FINAL ");
	print_routing_table();	
	printf("\n\n");
}
