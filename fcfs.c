#include <stdio.h>
int main()
{
    int i, j, n, temp, at[10], bt[10], ct[10], wt[10], tat[10], cur_time = 0;
    float avg_wt, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[10];
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (cur_time < at[i])
            cur_time = at[i];
        ct[i] = cur_time + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        cur_time = ct[i];
    }
    avg_wt = 0;
    avg_tat = 0;
    for (i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("Process\tArrival Time\tBurst Time\tCompletion time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f\nAverage turn around time: %.2f\n", avg_wt, avg_tat);
    return 0;
}