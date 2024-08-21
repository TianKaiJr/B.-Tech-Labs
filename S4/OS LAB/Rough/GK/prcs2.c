#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
int main() 
{
int pid,pid1,pid2,c_pid;
pid=fork();
if (pid==-1) 
{
printf("process failed\n");
exit(0);
}   
if (pid != 0) 
{
printf("This is child process\n");
printf("Process id is %d \n", getpid());
} 
else 
{ 
c_pid=wait(NULL);
printf("This is parent process\n");
printf("Process id is %d \n", getpid());
}
}
