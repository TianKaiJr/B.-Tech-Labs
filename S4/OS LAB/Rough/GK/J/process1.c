//Jiffina Rodrigues
//02
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
pid_t pid;
pid=fork();
if(pid<0)
printf("fork failed");
else if(pid==0)
printf("process is child \n pid of child is %d and pid of parent is %d\n",getpid(),getppid());
else
printf("\nprocess is parent \n pid of child is %d and pid of parent is %d",getpid(),getppid());
}
