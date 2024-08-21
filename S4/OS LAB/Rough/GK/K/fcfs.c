#include<stdio.h>

struct process{
int pid;
float at,bt,ct,tat,wt,st;
}a[100],temp;

void fcfs(int n){
	int i,j;
	float avgwt=0,avgtat=0,time = 0,k=0;
	//Sorting in Based on ArrivalTime
	for(i=0;i<n;i++){
	for(j=0;j<n-i-1;j++){
	if(a[j].at > a[j+1].at){
	temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
	printf("%d %d",a[j].pid,a[j+1].pid);
	}
	}
	}
	//Printing the gantt chart
	printf("---Gantt Chart--- \n");
	for(i=0;i<n;){
	if(a[i].at <= time){
	if(k!=0){
	printf("%f -> %f ::> NULL\n",time-k,time);
	k=0;
	}
	a[i].st = time;
	time += a[i].bt;
	a[i].ct = time;
	a[i].tat = a[i].ct - a[i].at;
	a[i].wt = a[i].tat - a[i].bt;
	avgwt+=a[i].wt;
	avgtat+=a[i].tat;
	printf("%f -> %f ::> P%d\n",a[i].st,time,a[i].pid);
	i++;
	}
	else{
	k++;
	++time;
	}
	}
	avgwt/=n;
	avgtat/=n;
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
	printf("Average TAT ==> %f\n",avgtat);
	printf("Average WT ==> %f\n",avgwt);
	}
void main(){
	int n;
	printf("Enter No of Process:");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
	a[i].pid = i+1;
	printf("Process %d:\n",i+1);
	printf("ArrivalTime ==>");
	scanf("%f",&a[i].at);
	printf("BurstTime ==>");
	scanf("%f",&a[i].bt);
	}
	fcfs(n);
	}
