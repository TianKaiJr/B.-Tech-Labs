#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,in,out,bsize,bucket=0,dropped_packets;
	
	printf("Enter Bucket size = ");
	scanf("%d",&bsize);
	
	printf("Enter Number of inputs = ");
	scanf("%d",&n);
	
	printf("Enter Outgoing packet rate = ");
	scanf("%d",&out);
	
	while(n!=0)
	{
		printf("\nEnter Incoming Packet Size = ");
		scanf("%d",&in);
		
		if(in+bucket>=bsize)
		{
			dropped_packets=(in+bucket)-bsize;
			printf("Dropped packet = %d\n",dropped_packets);
        			bucket=bsize;
			printf("Bucket status :: %d packets out of %d\n",bucket,bsize);
		}
		else
		{
			bucket= bucket+in;
			printf("Bucket status :: %d packets out of %d\n",bucket,bsize);
		}
		bucket=bucket-out;
		
		if(bucket<0)
		{
			printf("After Outgoing Bucket status :: 0 out of %d\n",bsize);
			bucket=0;
		}
		else
		{
			printf("After Outgoing Bucket status :: %d out of %d\n",bucket,bsize);
			n--;
		}
	}
}	
