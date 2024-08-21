#include<stdio.h>
#include<unistd.h>

void main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("exec starts");
		execl("/bin/ls","ls","-l",(char)(0));
		printf("exec didn't work");
	}
	else
	{
		wait(0);
		printf("parent = Is is completed in child\n");
	}
}
