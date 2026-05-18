#include <stdio.h>

int main()
{
    int i, n;
    int at[10], bt[10], pr[10], ct[10], wt[10], tat[10];
    int completed[10] = {0}, pid[10];
    int cur_time = 0, done = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter arrival time for process %d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", pid[i]);
        scanf("%d", &bt[i]);
        printf("Enter priority for process %d: ", pid[i]);
        scanf("%d", &pr[i]);
    }

    while (done < n)
    {
        int idx = -1;
        int max_pr = -1;

        
        for (i = 0; i < n; i++)
        {
            if (at[i] <= cur_time && !completed[i] && pr[i] > max_pr)
            {
                max_pr = pr[i];
                idx = i;
            }
        }

        if (idx == -1)
        {
            cur_time++; 
        }
        else
        {
            completed[idx] = 1;
            cur_time += bt[idx];
            ct[idx] = cur_time;           
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx]; 
                                          
            done++;
            avg_wt += wt[idx];
            avg_tat += tat[idx];
        }
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}