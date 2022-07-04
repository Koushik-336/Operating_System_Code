#include<stdio.h>
int main()
{
    int n;
    printf("Enter Process : ");
    scanf("%d",&n);
    int i,j,k,l;
    int AT[50],BT[50],CT[50],TAT[50],WT[50];
    printf("Enter AT : ");
    for(i=0;i<n;i++)
        scanf("%d",&AT[i]);
    printf("Enter BT : ");
    for(j=0;j<n;j++)
        scanf("%d",&BT[j]);
    for(k=0;k<n;k++)
    {
        if(k==0)
            CT[k]=AT[k]+BT[k];
        else
            CT[k]=CT[k-1]+BT[k];
    }
    for(k=0;k<n;k++)
    {
        TAT[k]=CT[k]-AT[k];
        WT[k]=TAT[k]-BT[k];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(l=0;l<n;l++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",l+1,AT[l],BT[l],CT[l],TAT[l],WT[l]);
}
