#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int pid,pid1,pid2,c_pid;
	pid=fork();
	
	if(pid == -1)
	{
		printf("Error in process creation \n");
		exit(1);
	}
	if(pid != 0)
	{
		c_pid=wait(NULL);
		pid1=getpid();
		printf("Process ID of Parent = %d\n",pid1);
	}
	else
	{
		pid2=getpid();
		printf("Process ID of Child = %d\n",pid2);
	}
	
}
