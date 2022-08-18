//Banker's Algorithm

#include<stdio.h>
int main()
{
    int n,m,i,j,k;
    printf("Number of processes: ");
    scanf("%d",&n);
    printf("Number of resources: ");
    scanf("%d",&m);
    int allocation[n][m],max[n][n],available[m],need[n][m],f[n],ans[n],ind=0;
    printf("Enter allocation matrix\n");
    printf("A B C\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            scanf("%d",&allocation[i][j]);
    }
    printf("Enter max matrix\n");
    printf("A B C\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    }
    printf("Enter available Resources: \n");
    printf("A B C\n");
    for(i=0; i<m; i++)
        scanf("%d",&available[i]);
    for(k=0; k<n; k++)
    {
        f[k]=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            need[i][j]=max[i][j]-allocation[i][j];
    }
    int y=0;
    for(k=0; k<m; k++)
    {
        for(i=0; i<n; i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(j=0; j<m; j++)
                {
                    if(need[i][j]>available[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[ind++]=i;
                    for (y=0; y<m; y++)
                        available[y]+=allocation[i][y];
                    f[i]=1;
                }
            }
        }
    }
    printf("Following is the SAFE Sequence\n<");
    for(i=0; i<n-1; i++)
        printf("P%d ,",ans[i]);
    printf("P%d >",ans[n-1]);
    return (0);
}
