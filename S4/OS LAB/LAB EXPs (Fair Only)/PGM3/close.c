#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int fd1=open("hi.txt",O_RDONLY);
	if(fd1<0)
	{
		perror("c1");
		exit(1);
	}
	printf("Opened the file discriptor = %d\n",fd1);
	if(close(fd1)<0)
	{
		perror("c1");
		exit(1);
	}
	printf("Closed the file discriptor.\n");
}
