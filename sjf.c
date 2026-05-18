#include <stdio.h>

int main()
{
    int i, n;
    int at[10], bt[10], ct[10], wt[10], tat[10];
    int completed[10] = {0}, pid[10];
    int cur_time = 0, done = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }

    while (done < n)
    {
        int idx = -1;
        int min_bt = 9999;

        // Find process with shortest burst among arrived and not completed
        for (i = 0; i < n; i++)
        {
            if (at[i] <= cur_time && !completed[i] && bt[i] < min_bt)
            {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx == -1)
        {
            cur_time++; // CPU idle until a process arrives
        }
        else
        {
            completed[idx] = 1;
            ct[idx] = cur_time + bt[idx]; // completion time
            tat[idx] = ct[idx] - at[idx]; // turnaround time
            wt[idx] = tat[idx] - bt[idx]; // waiting time

            cur_time = ct[idx]; // advance current time
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
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}