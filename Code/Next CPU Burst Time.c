//Next CPU Burst Time

#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter number of process: ");
    scanf("%d",&n);
    float sf,PT;
    int AT[100];
    for(i=0;i<n;i++)
    {
       scanf("%d",&AT[i]);
    }
    printf("Enter smoothing factor: ");
    scanf("%f",&sf);
    printf("Enter 1st predicted time: ");
    scanf("%f",&PT);
    printf("Actual Time\tPredicted Time\n");
    for(i=0;i<n;i++)
    {
        PT=sf*AT[i]+(1-sf)*PT;
        printf("%d\t\t%.2f\n",AT[i],PT);
    }
    return 0;
}
