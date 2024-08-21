#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
int i;
void *shared_memory;
int shmid;
char buff[100];
shmid=shmget((key_t)2345,1024,0666);
printf("key of shared memory is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("Process attched at %p\n",shared_memory);
printf("Data read from shared memory is:%s",(char*)shared_memory);
}
