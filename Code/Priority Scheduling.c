#include<stdio.h>
#define max 100
int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int i,j,k;
    int temp;
    int P[max],BT[max],CT[max],WT[max],PR[max];
    printf("Enter Process : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&P[i]);
    }
    printf("Enter Burst Time : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&BT[i]);
    }
    printf("Enter Priority: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&PR[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(PR[i]>PR[j])
            {
                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;

                temp=PR[i];
                PR[i]=PR[j];
                PR[j]=temp;

                temp=P[i];
                P[i]=P[j];
                P[j]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(i==0)
            CT[i]=BT[i];
        else
            CT[i]=CT[i-1]+BT[i];
    }
    for(i=0; i<n; i++)
    {
        WT[i]=CT[i]-BT[i];
    }
    int p[n],bt[n],ct[n],wt[n],pr[n];
    for(i=0;i<n;i++)
    {
        int temp2=P[i];
        p[temp2]=temp2;
        bt[temp2]=BT[i];
        pr[temp2]=PR[i];
        ct[temp2]=CT[i];
        wt[temp2]=WT[i];
    }
    printf("Process\tBT\tPR\tCT/TAT\tWT\n");
    for(k=0;k<n;k++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",p[k],bt[k],pr[k],ct[k],wt[k]);
    }
}
