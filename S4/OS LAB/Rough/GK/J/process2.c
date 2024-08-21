//Jiffina Rodrigues
//02
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
int pid,pid_1,pid_2,c_pid;
pid=fork();
if(pid==-1)
{
printf("error in process creation");
exit(1);
}
else if(pid!=0)
{
c_pid=wait(NULL);
pid_1=getpid();
printf("pid of parent is %d \n",pid_1);
}
else
{
pid_2=getpid();
printf(" pid of child is %d \n",pid_2);
}
}
