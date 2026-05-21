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
void look(int req[],int n, int head)
{
    int temp[n];
    int total=0,index;
    for(int i=0;i<n;i++)
    {
        temp[i]=req[i];
    }
    sort(temp,n);
    printf("LOOK Path: %d",head);
    for(int i=0;i<n;i++)
    {
        if(temp[i]>=head)
        {
            index=i;
            break;
        }
    }
    for(int i=index;i<n;i++)
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
    int i, n,head,req[n];
    printf("Enter no.of requests: ");
    scanf("%d",&n);
    printf("Enter requests: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d",&head);
    look(req,n,head);
    return 0;
}