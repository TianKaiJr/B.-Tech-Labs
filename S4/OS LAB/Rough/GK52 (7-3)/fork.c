#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	fork();
	fork();
	fork();
	printf("HELLO WORLD\n");
}
