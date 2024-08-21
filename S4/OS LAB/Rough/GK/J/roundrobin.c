#include<stdio.h>
struct process
{
int pid,at,bt,ct,tat,wt,rt;
}p[100],temp;
void roundrobin(struct process a[100],int n,int tq)
{
int i,j,t,rem_bt[n],flag=0,time=0;
float avgat=0,avgwt=0;
char s[]="";
for(i=0;i<n;i++)
{
rem_bt[i]=a[i].bt;
}
printf("\n GANTT CHART \n");
while(1)
{
flag=0;
for(i=0;i<n;i++)
{
if(rem_bt[i]>0)
{
flag=1;
if(rem_bt[i]>tq && a[i].at<=time)
{
rem_bt[i]=tq;
time+=tq;
printf("%d-%d->p%d\n",time-tq,time,a[i].pid);
}
else if(a[i].at<=time)
{
printf("%d-",time);
time+=rem_bt[i];
printf("%d->p%d\n",time,a[i].pid);
a[i].ct=time;
a[i].tat=a[i].ct-a[i].at;
a[i].wt=a[i].tat-a[i].bt;
rem_bt[i]=0;
avgat+=a[i].tat;
avgwt+=a[i].wt;
}
}
}
if(flag==0)
break;
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
printf("\n Process Id AT%s BT%s CT%s TAT%s WT\n",s,s,s,s);
for(i=0;i<n;i++)
{
printf("%6d %d %d %d %d %d\n", a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
}
printf("\n Avgtat:%f\n",avgat);
printf("\n Avgwt:%f\n",avgwt);
}
int main()
{
int n,i,tq;
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
p[i].rt=p[i].bt;
}
printf("\n enter the time quantum:");
scanf("%d",&tq);
roundrobin(p,n,tq);
return 0;
}
