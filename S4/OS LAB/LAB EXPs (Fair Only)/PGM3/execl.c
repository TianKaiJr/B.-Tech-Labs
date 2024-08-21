#include<stdio.h>
#include<unistd.h>

void main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("EXEC STARTS");
		execl("/bin/ls","ls","-l",(char)(0));
		printf("EXEC DIDN'T WORK");
	}
	else
	{
		wait(0);
		printf("PARENT = 'ls' is completed in CHILD\n");
	}
}
