#include<stdio.h>

void sortAT(int n,int pno[], int at[], int bt[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                int temp_pno = pno[j];
                pno[j] = pno[j + 1];
                pno[j + 1] = temp_pno;
                
                int temp_at = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp_at;

                int temp_bt = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp_bt;
            }
        }
    }
}

void sortBT(int n,int pno[], int at[], int bt[],int ct[],int tat[],int wt[],int rt[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int temp_pno = pno[j];
                pno[j] = pno[j + 1];
                pno[j + 1] = temp_pno;
                
                int temp_at = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp_at;

                int temp_bt = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp_bt;
                
                int temp_ct = ct[j];
                ct[j] = ct[j + 1];
                ct[j + 1] = temp_ct;
                
                int temp_tat = tat[j];
                tat[j] = tat[j + 1];
                tat[j + 1] = temp_tat;
                
                int temp_wt = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp_wt;
                
                int temp_rt = rt[j];
                rt[j] = rt[j + 1];
                rt[j + 1] = temp_rt;
            }
        }
    }
}

void calc_SJF(int n,int pno[], int at[], int bt[], int ct[], int tat[], int wt[], int rt[])
{
    int i,twt = 0,ttat = 0,trt = 0,curt = 0;

    for (i = 0; i < n; i++)
    {	
    	if(i==0)
    	{
    		sortAT(n,pno,at,bt);
    		goto START;
    	}
    	else
    	{
    		sortBT(n,pno,at,bt,ct,tat,wt,rt);
    		goto START;
    	}
    	START:
        if (curt > at[i])
        {
            ct[i] = curt + bt[i];
        }
        else 
        {
            ct[i] = at[i] + bt[i];
        }

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];
        if (wt[i] < 0) 
        {
            wt[i] = 0;
        }

        rt[i] = wt[i];

        curt = ct[i];

        twt += wt[i];
        ttat += tat[i];
        trt += rt[i];
    }

    float avg_waiting = (float)twt / n;
    float avg_turnaround = (float)ttat / n;
    float avg_response = (float)trt / n;

    printf("\n+------------+--------------+------------+-----------------+-----------------+--------------+---------------+\n");
    printf("| Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time | Response Time |\n");
    printf("+------------+--------------+------------+-----------------+-----------------+--------------+---------------+\n");
    for (i = 0; i < n; i++) 
    {
        printf("| %10d | %12d |%11d | %15d |  %14d |%13d |%14d |\n",pno[i],at[i],bt[i],ct[i], at[i],wt[i],rt[i]);
    }
    printf("+------------+--------------+------------+-----------------+-----------------+--------------+---------------+\n");
    printf("\nAverage Turn Around Time = %.2f\n", avg_turnaround);
    printf("Average Waiting Time = %.2f\n", avg_waiting);
    printf("Average Response Time = %.2f\n", avg_response);
}

void main()
{
    int n;
    printf("Number of pnoes = ");
    scanf("%d", &n);

    int pno[n],at[n],bt[n],ct[n],tat[n],wt[n],rt[n];

    for (int i = 0; i < n; i++)
    {
        pno[i]=i+1;
        printf("[pno %d][AT] - ",i+1);
        scanf("%d", &at[i]);
        printf("[pno %d][BT] - ",i+1);
        scanf("%d", &bt[i]);
    }
    
    calc_SJF(n,pno,at,bt,ct,tat,wt,rt);
}








