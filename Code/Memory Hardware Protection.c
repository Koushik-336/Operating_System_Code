// Memory Hardware Protection

#include<stdio.h>
#define max 100
int main()
{
    int n,P[max],B[max],L[max],i,RA,RP;
    printf("Enter no of process: ");
    scanf("%d",&n);
    printf("P\tB\tL\n");
    for(i=0; i<n; i++)
    {
        scanf("%d%d%d",&P,&B,&L);
    }
    while(-1)
    {
        printf("Enter request process: ");
        scanf("%d",&RP);
        printf("Enter request address: ");
        scanf("%d",&RA);
        if(RA>=B[RP] && RA<(B[RP]+L[RP]))
            printf("Accepted\n");
        else
            printf("Not accepted\n");;
    }
    return 0;
}
