#include<stdio.h>

int pn;
int pno[10],at[10],bt[10],ct[10],tat[10],wt[10],rt[10];

void sortAT();
void sortBT();
void calc_SJF();

void main()
{
    printf("Number of Processes = ");
    scanf("%d", &pn);

    for (int i = 0; i < pn; i++)
    {
        pno[i]=i+1;
        printf("[Processes %d][AT] - ",i+1);
        scanf("%d", &at[i]);
        printf("[Processes %d][BT] - ",i+1);
        scanf("%d", &bt[i]);
    }
    
    sortAT(pn);
    calc_SJF(0,1);
    sortBT(pn);
    calc_SJF(1,pn);
}

void sortAT(int n)
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

void sortBT(int n)
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

void calc_SJF(int i,int n)
{
    int twt = 0,ttat = 0,trt = 0,curt = 0;

    for ( i ; i < n; i++) 
    {	
    	if (curt > bt[i])
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










