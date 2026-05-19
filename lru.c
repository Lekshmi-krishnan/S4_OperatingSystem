#include<stdio.h>
#define MAX 50
int ispresent(int frame[],int f,int page)
{
    for(int i=0;i<f;i++)
    {
        if(frame[i]==page)
        {
            return 1;
        }
    }
    return 0;
}
int findlru(int time[],int f)
{
    int min=0;
    for(int i=1;i<f;i++)
    {
        if(time[i]<time[min])
        {
            min=i;
        }
    }
    return min;
}
int getindex(int frame[],int f,int page)
{
    for(int i=0;i<f;i++)
    {
        if(frame[i]==page)
        {
            return i;
        }

    }
    return -1;
}
void lru(int page[],int n,int f)
{
    int frame[MAX],time[MAX];
    int count=0,hit=0,fault=0;
    for(int i=0;i<f;i++)
    {
        frame[i]=-1;
        time[i]=0;
    }
    printf("\n--- LRU Page Replacement ---");
    for(int i=0;i<n;i++)
    {
        if(!ispresent(frame,f,page[i]))
        {
            int index=findlru(time,f);
            frame[index]=page[i];
            count++;
            time[index]=count;
            fault++;
            printf("\n%d F -> ",page[i]);
        }else{
            int index;
            index=getindex(frame,f,page[i]);
            count++;
            time[index]=count;
            hit++;
            printf("\n%d H -> ",page[i]);
        }
        for (int j = 0; j < f; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal Hits: %d", hit);
    printf("\nTotal Faults: %d", fault);
}
int main() {
    int page[MAX], n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter %d page reference numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    printf("\nReference string entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", page[i]);
    }
    printf("\n");

    lru(page, n, f);

    return 0;
}
