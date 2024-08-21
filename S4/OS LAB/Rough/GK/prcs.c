#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() 
{
pid_t pid;
pid = getpid();
pid = fork();
if (pid < 0) 
{
printf("process failed\n");
return 1;
}   
if (pid == 0) 
{
printf("This is child process\n");
printf("Process id is %d \n", getpid());
} 
else 
{ 
wait(NULL);
printf("This is parent process\n");
printf("Process id is %d \n", getpid());
}
return 0;
}
