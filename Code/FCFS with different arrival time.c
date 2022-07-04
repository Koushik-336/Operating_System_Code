#include<stdio.h>
#define max 100
int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int i,j,k;
    int temp;
    int P[max],AT[max],BT[max],CT[max],TAT[max],WT[max];
    printf("Enter Process : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&P[i]);
    }
    printf("Enter Arrival Time : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&AT[i]);
    }
    printf("Enter Brust Time : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&BT[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(AT[i]>AT[j])
            {
                temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;

                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;

                temp=P[i];
                P[i]=P[j];
                P[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
            CT[i]=AT[i]+BT[i];
        else
            CT[i]=CT[i-1]+BT[i];
    }
    for(i=0;i<n;i++)
    {
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(k=0;k<n;k++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",P[k],AT[k],BT[k],CT[k],TAT[k],WT[k]);
    }
    int p[n],at[n],bt[n],ct[n],tat[n],wt[n];
    for(i=0;i<n;i++)
    {
        int temp2=P[i]-1;
        p[temp2]=temp2;
        at[temp2]=AT[i];
        bt[temp2]=BT[i];
        ct[temp2]=CT[i];
        tat[temp2]=TAT[i];
        wt[temp2]=WT[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(k=0;k<n;k++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[k]+1,at[k],bt[k],ct[k],tat[k],wt[k]);
    }
}
