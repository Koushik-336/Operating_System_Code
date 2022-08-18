#include<stdio.h>
#define max 100
int main()
{
    int n,i,count=0,ct=0,temp,tq;
    int P[max],TAT[max],CT[max],WT[max],BT[max],REM_BT[max];
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("Enter Process: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&P[i]);
    }
    printf("Enter Burst Time: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&BT[i]);
        REM_BT[i]=BT[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);
    while(1)
    {
        for(i=0,count=0; i<n; i++)
        {
            temp=tq;
            if(REM_BT[i]==0)
            {
                count++;
                continue;
            }
            if(REM_BT[i]>tq)
            {
                REM_BT[i]=REM_BT[i]-tq;
            }
            else if(REM_BT[i]>=0)
            {
                temp=REM_BT[i];
                REM_BT[i]=0;
            }
            ct=ct+temp;
            TAT[i]=ct;
        }
        if(n==count)
            break;
    }
    for(i=0; i<n; i++)
    {
        CT[i]=TAT[i];
        WT[i]=TAT[i]-BT[i];
    }
    printf("Process\tBT\tCT\tTAT\tWT\n");
    for(i=0; i<n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",P[i],BT[i],CT[i],TAT[i],WT[i]);
    }
}
