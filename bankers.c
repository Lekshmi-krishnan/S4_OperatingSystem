#include<stdio.h>
int main()
{
    int n,i,j,m;
    int alloc[50][50],avail[50],need[50][50],max[50][50],work[50],finish[50],safeseq[50];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources :");
    scanf("%d",&m);
    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter maximum matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
     printf("Enter available matrix:\n");
    for(j=0;j<m;j++)
        {
            scanf("%d",&avail[j]);
            work[j]=avail[j];
        }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    int count=0;
    while(count<n)
    {
        int found=0;
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        break;
                    }
                }
                if(j==m){
                    for(int k=0;k<m;k++)
                    {
                        work[k]+=alloc[i][k];
                    }
                    safeseq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found)
        {
            printf("System is not in safe state.\n");
            return 0;
        }
    }
    printf("System is in safe state.\nSafe sequence is: ");
    for(i=0;i<n;i++)
    {
        printf("P%d ",safeseq[i]);
    }
    printf("\n");
    return 0;
}