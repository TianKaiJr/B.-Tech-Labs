#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	printf("PID of execv.c = %d\n",getpid());
	char *args[]={"HELLO","C","PROGRAMMING",NULL};
	execv("./stat.out",args);
	printf("Back To execv.c");
	return 0;
}

