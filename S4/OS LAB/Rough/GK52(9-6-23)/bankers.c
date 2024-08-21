#include <stdio.h>
#define MAX 10

int pn,pno[MAX],AM[MAX][3],MM[MAX][3],AVM[MAX][3],NM[MAX][3];

void main()
{
	printf("Enter the Number [Processes] >> ");
	scanf("%d",&pn);		
	printf("Enter the ALLOCATED MATRIX\n");
	for(int i=0;i<pn;i++)
	{
		printf("ALLOCATED P%d [A_B_C_D] >> ",i+1);
		scanf("%d %d %d %d",&AM[i][0],&AM[i][1],&AM[i][2],&AM[i][3]);
	}
	printf("Enter the MAX MATRIX\n");
	for(int i=0;i<pn;i++)
	{
		printf("MAX P%d [A_B_C_D] >> ",i+1);
		scanf("%d %d %d %d",&MM[i][0],&MM[i][1],&MM[i][2],&MM[i][3]);
	}
	printf("Enter the AVAILABLE MATRIX\nAVAILABLE RESOURCE [A_B_C_D] >> ");
	scanf("%d %d %d %d",&AVM[0][0],&AVM[0][1],&AVM[0][2],&AVM[0][3]);
	
	for(i=0;i<pn;i++)
	{
		NM[i][0]=MM[i][0]-AM[i][0];
		NM[i][1]=MM[i][1]-AM[i][1];
		NM[i][2]=MM[i][2]-AM[i][2];
		NM[i][3]=MM[i][3]-AM[i][3];
	}
	
	
}
