(9)
#include <stdio.h>
#include <stdlib.h>
void tsp(int s,int vis[]);
int sum=0,i,n,g[10][10],tmp,min,u;
int main()
{
    int vis[10],j,s,tmp;
    float mincost,error;
    printf("\nenter the number of cities:");
    scanf("%d",&n);
    printf("\nenter the distance matrix:\n");
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        for(j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
    }
    printf("\nenter the minimum cost obtained using alternate algorithm:");
    scanf("%f",&mincost);

    printf("\nenter the starting city:");
    scanf("%d",&s);

    tmp=s;
    vis[s]=1;
    tsp(s,vis);
    sum=sum+g[u][tmp];
    printf("%5d",u);
    printf("%5d",tmp);

    printf("\nThe total distance travelled is %d",sum);
    error=sum/mincost;
    printf("the error in the approximation is %f",(error-1)*100);
}

void tsp(int s,int vis[])
{
    min=999;
    printf("%5d",s);
    for(i=1;i<=n;i++)
{
        if(g[s][i]<min && vis[i]==0)
    {
        min=g[s][i];
        u=i;
    }
}
    sum+=min;
    vis[u]=1;
    for(i=1;i<=n;i++)
        if(vis[i]==0)
        tsp(u,vis);
}