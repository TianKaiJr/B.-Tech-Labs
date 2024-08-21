#include<stdio.h>

void main()
{
	FILE *rf,*wf;
	char read[100],write[100];
	
	rf=fopen("read.txt","r");
	
	if(rf==NULL)
		printf("File Not Found!!");
	else
	{
		wf=fopen("write.txt","w");
		while(fgets(read,sizeof(read),rf)!=NULL)
		{
			printf("%s",read);
			fprintf(wf,"%s",read);
		}
		fclose(wf);
		fclose(rf);
	}	
}
