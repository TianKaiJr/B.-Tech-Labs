#include<stdio.h>
struct process
{
int pid,at,bt,ct,tat,wt,st,priority;
}p[100],temp;
int priority(struct process a[100],int n)
{
int i,j,max;
float avgat=0,avgwt=0,time=0,z=0;
char s[]="";
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
if(a[j].at>a[j+1].at)
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
printf("\n GANTT CHART \n");
for(i=0;i<n;)
{
max=i;
for(j=i+1;j<n;j++)
if(a[j].priority>a[max].priority && a[j].at<=time)
max=j;
if(i!=max)
{
temp=a[i];
a[i]=a[max];
a[max]=temp;
}
if(a[i].at<=time)
{
if(z!=0)
{
printf("%f-%f->NULL\n",time-z,time);
z=0;
}
a[i].st=time;
time+=a[i].bt;
a[i].ct=time;
a[i].tat=a[i].ct-a[i].at;
a[i].wt=a[i].tat-a[i].bt;
avgat+=a[i].tat;
avgwt+=a[i].wt;
printf("%d-%d->p%d\n",a[i].st,a[i].ct,a[i].pid);
i++;
}
else
{
z++;
++time;
}
}
avgat/=n;
avgwt/=n;
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
if(a[j].pid>a[j+1].pid)
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
printf("\n process Id AT%s BT%s CT%s TAT%s WT\n",s,s,s,s);
for(i=0;i<n;i++)
{
printf("%6d %d %d %d %d %d\n", a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
}
printf("\n Avgtat:%f\n",avgat);
printf("\n Avgwt:%f\n",avgwt);
}
int main()
{
int n,i;
printf("enter the no.of processes:");
scanf("%d",&n);
printf("enter the arrival time and burst time:");
for(i=0;i<n;i++)
{
p[i].pid=i+1;
printf("process %d\n",p[i].pid);
printf("arrival time");
scanf("%d",&p[i].at);
printf("burst time:");
scanf("%d",&p[i].bt);
printf("Priority:");
scanf("%d",&p[i].priority);
}
priority(p,n);
return 0;
}

