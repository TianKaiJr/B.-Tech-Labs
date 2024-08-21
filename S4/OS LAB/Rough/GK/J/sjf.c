#include<stdio.h>

struct process
{
    int pid , at, bt, ct, tat, wt, st;
} p[100], temp;

void sjf(struct process a[100], int n)
{
int i, j, min;
float avgat = 0, avgwt = 0, time = 0, z = 0;
char s[] = "";
for (i = 0; i < n - 1; i++)
for (j = 0; j < n - i - 1; j++)
if (a[j].at > a[j + 1].at)
{
temp = a[j];
a[j] = a[j + 1];
a[j + 1] = temp;
}
printf("\n GANTT CHART\n");
for (i = 0; i < n;)
{
min = i;
for (j = i + 1; j < n; j++)
if (a[j].bt < a[min].bt && a[j].at <= time)
min = j;
if (i != min)
{
temp = a[i];
a[i] = a[min];
a[min] = temp;
}
if (a[i].at <= time)
        {
            if (z != 0)
            {
                printf("%f-%f->NULL\n", time - z, time);
                z = 0;
            }
            a[i].st = time;
            time += a[i].bt;
            a[i].ct = time;
            a[i].tat = a[i].ct - a[i].at;
            a[i].wt = a[i].tat - a[i].bt;
            avgat += a[i].tat;
            avgwt += a[i].wt;
            printf("%d-%d->p%d\n", a[i].st, a[i].ct, a[i].pid);
            i++;
        }
        else
        {
            z++;
            ++time;
        }
    }
    avgat /= n;
    avgwt /= n;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j].pid > a[j + 1].pid)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    printf("\n   PId.  AT%s  BT%s  CT%s  TAT%s  WT\n",s,s,s,s);
    for (i = 0; i < n; i++)
    {
        printf("%6d  %d   %d   %d   %d   %d \n", a[i].pid, a[i].at, a[i].bt, a[i].ct, a[i].tat, a[i].wt);
    }
    printf("\n Avg TAT :%f", avgat);
    printf("\n Avg WT :%f\n", avgwt);
}

int main()
{
    int n, i;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time:\n");
    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("PROCESS %d\n", p[i].pid);
        printf("ARRIVAL TIME:");
        scanf("%d", &p[i].at);
        printf("BURST TIME:");
        scanf("%d", &p[i].bt);
    }
    sjf(p, n);
    return 0;
}



