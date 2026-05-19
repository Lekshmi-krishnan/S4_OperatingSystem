#include<stdio.h>
#include<stdlib.h>

void sstf(int req[], int n, int head)
{
    int visited[n];
    int total=0,count=0;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }printf("SSTF path: %d",head);
    while(count<n)
    {
         int min=9999,index=-1;
         for (int i=0;i<n;i++)
         {
             if(!visited[i])
             {
                int dist=abs(head-req[i]);
                if(dist<min)
                {
                    min=dist;
                    index=i;
                     
                }
              }
        }
        printf("->%d",req[index]);
        visited[index]=1;
        total+=min;
        head=req[index];
        count++;
    }
    printf("\nTotal head movement: %d", total);
    // Implementation for SSTF algorithm
}

int main()
{
    int n,req[n],head;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("Enter head position: ");
    scanf("%d",&head);
    printf("Enter requests: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    sstf(req,n,head);
    return 0;
}