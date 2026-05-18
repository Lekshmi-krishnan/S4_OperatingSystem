#include <stdio.h>

int main()
{
    int i, n;
    int at[10], bt[10], ct[10], wt[10], rt[10], tat[10];
    int completed = 0, pid[10];
    int cur_time = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n)
    {
        int idx = -1;
        int min_rt = 9999;

        // Find process with shortest burst among arrived and not completed
        for (i = 0; i < n; i++)
        {
            if (at[i] <= cur_time && rt[i] > 0 && rt[i] < min_rt)
            {
                min_rt = rt[i];
                idx = i;
            }
        }

        if (idx == -1)
        {
            cur_time++; // CPU idle until a process arrives
        }
        else
        {
            rt[idx]--;
            cur_time++;
            if (rt[idx] == 0)
            {
                completed++;
                ct[idx] = cur_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                avg_wt += wt[idx];
                avg_tat += tat[idx];
            }
        }
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}