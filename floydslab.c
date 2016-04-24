#include<stdio.h>
#include<omp.h>
#include<time.h>
int min(int a,int b)
{
	return a<b?a:b;
}
void floyds(int cost[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
}
void main()
{
	int cost[10][10],w,n,i,j;
	double t,s,a,f,speedup;
	clock_t CLK_TCK,s1,e1;

	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	}
	s1=clock();
	for(i=0;i<100000;i++)
	{
		floyds(cost,n);
	}
	e1=clock();

	f=(double)(e1-s1)/CLK_TCK;
	s=omp_get_wtime();
	#pragma omp parallel for
	for(i=0;i<1000;i++)
	{
		floyds(cost,n);
	}
	a=omp_get_wtime();

	t=(a-s)*1000;

	

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",cost[i][j]);
		printf("\n");
	}
	printf("\nThe shortest paths are:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j || cost[i][j] != 999)
				printf("\n <%d,%d>=%d",i,j,cost[i][j]);
		}
	}
	printf("\nTime taken for parallel execution=%lf",t);
	printf("\nTime taken for sequential execution=%lf",f*1000);
}