#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>
struct dirent *dptr;
int main(int argc,char *argv[])
{
char buff[100];
struct stat stats;
DIR *dirp;
printf("\n\n Enter directory name");
scanf("%s",buff);
if((dirp=opendir(buff))==NULL||stat(buff,&stats))
{
printf("The given directory does not exist");
exit(1);
}
while(dptr=readdir(dirp))
{
printf("%s\n",dptr->d_name);
}
closedir(dirp);
}

