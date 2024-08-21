#include<stdio.h>

struct process{
int pid;
float at,bt,ct,tat,wt,st,rt;
}a[100],temp;

void roundrobin(int n,int tq)
{
int i,j,t,rem_bt[n],flag=0,time=0;
float avgat=0,avgwt=0;
char s[]="";
for(i=0;i<n;i++)
rem_bt[i]=a[i].bt;
printf("\n GANTT CHART\n");
while(1){
flag=0;
for(i=0;i<n;i++){
if(rem_bt[i]>0){
flag=1;
if(rem_bt[i]>tq && a[i].at<=time){
rem_bt[i] -= tq;
time +=tq;
printf("%d-%d->%d\n",time-tq,time,a[i].pid);
}
else if(a[i].at<=time){
printf("%d-",time);
time +=rem_bt[i];
printf("%d->p%d\n",time,a[i].pid);
a[i].ct=time;
a[i].tat=a[i].ct-a[i].at;
a[i].wt=a[i].tat-a[i].bt;
rem_bt[i]=0;
avgat +=a[i].tat;
avgwt +=a[i].wt;
}
}
}
if(flag==0)
break;
}
avgwt/=n;
	avgat/=n;
	//sorting to pid 
	
	for(i=0;i<n;i++){
	for(j=0;j<n-i-1;j++){
	if(a[j].pid > a[j+1].pid){
	temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
	}
	}
	}
	//print table
	printf("ProcessID\tArrivalTime\tBurstTime\tCompleteionTime\t\tTurnAroundTime\t\tWaitingTime\n");
	for(i=0;i<n;i++){
	printf("%d\t\t%f\t%f\t%f\t\t%f\t\t%f\n",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
	}
	printf("Average TAT ==> %f\n",avgat);
	printf("Average WT ==> %f\n",avgwt);
	}
	void main(){
	int i,tq,n;
	printf("Enter No of Process:");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
	a[i].pid = i+1;
	printf("Process %d:\n",i+1);
	printf("ArrivalTime ==>");
	scanf("%f",&a[i].at);
	printf("BurstTime ==>");
	scanf("%f",&a[i].bt);
	a[i].rt=a[i].bt;
	}
	printf("\nenter the time quantum:");
	scanf("%d",&tq);
	roundrobin(n,tq);
	return 0;
	}
