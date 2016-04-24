(4)knap dynamic
#include <stdio.h>
#include <stdlib.h>
int w[10],p[10],v[10][10],n,i,j,cap,x[10]={0};

#include <stdlib.h>

int main()
{
    int i,p[10],w[10],n,m;
    printf("enter the no of items:\n");
    scanf("%d",&n);
    printf("entre weights of the items:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    printf("entre the profit of the items:");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("enter the capacity  of the knapsack:");
    scanf("%d",&m);
    knapsack(p,w,n,m);
}
void knapsack(int p[],int w[],int n,int m)
{
    int i,j,x[10],v[10][10];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(j<w[i])
             v[i][j]=v[i-1][j];
             else
                v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
        }
    }
    printf("the table for the knapsack is:\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    printf("the optiomal solution of the knapsack is %d\n",v[n][m]);
    for(i=0;i<=n;i++)
        x[i]=0;
    i=n;
    j=m;
    while(i!=0&&j!=0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    printf("the items selected for the optimal solution is:\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
            printf("%5d",i);
    }
}
int max(int i,int j)
{
    return((i>j)?i:j);
}
