#include<stdio.h>
#define MAX 10

int n,AT[MAX],BT[MAX],CT[MAX],TAT[MAX],WT[MAX],RT[MAX],avgtat=0,avgwt=0;

void main()
{
	int i;
	
	printf("FCFS SCHEDULING ALGORITHM\n");
	printf("Number of process >> ");
	scanf("%d",&n);
	
	printf("Enter the ARRIVAL TIME of the processes (in arrival order)\n")
	for(i=0;i<n;i++)
	{
		printf("AT[P%d] >> ",i+1);
		scanf("%d",&AT[i]);
	}
	
	printf("Enter the BURST TIME of the processes (in correspondence with AT)\n")
	for(i=0;i<n;i++)
	{
		printf("BT[P%d] >> ",i+1);
		scanf("%d",&BT[i]);
	}
	
	for(i=0;i<n;i++)
	{
		
	}	
}
