#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void scan(int req[],int n, int head,int max)
{
    int temp[n+2];
    int total=0,index;
    for(int i=0;i<n;i++)
    {
        temp[i]=req[i];
    }
    temp[n]=0;
    temp[n+1]=max-1;
    sort(temp,n+2);
    printf("SCAN Path: %d",head);
    for(int i=0;i<n+2;i++)
    {
        if(temp[i]>=head)
        {
            index=i;
            break;
        }
    }
    for(int i=index;i<n+2;i++)
    {
        printf("->%d",temp[i]);
        total+=abs(head-temp[i]);
        head=temp[i];
    }
    for(int i=index-1;i>=0;i--)
    {
        printf("->%d",temp[i]);
        total+=abs(head-temp[i]);
        head=temp[i];
    }
    printf("Total head movement :%d\n",total);
    
}
int main()
{
    int i, n,head,max,req[n];
    printf("Enter disk size: ");
    scanf("%d",&max);
    printf("Enter no.of requests: ");
    scanf("%d",&n);
    printf("Enter requests: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d",&head);
    scan(req,n,head,max);
    return 0;
}