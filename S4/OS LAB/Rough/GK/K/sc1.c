#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
struct dirent *dptr;

int main(int argc,char*argv[])
{
char buff[100];
struct stat stats;
DIR *dirp;
printf("\n\nENTER DIRECTORY NAME :");
scanf("%s",buff);
if((dirp=opendir(buff))==NULL||stat(buff,&stats))
{
printf("the given directory does not exist");
exit(1);
}
while(dptr=readdir(dirp))
{
printf("%s\n",dptr->d_name);
}
closedir(dirp);
}


