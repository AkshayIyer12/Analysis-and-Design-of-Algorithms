(11)

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
  int i,j,k,n,d[100][100];
	double s1,s2,e1,e2,t1,t2;

	printf("\nenter the number of nodes:");
	scanf("%d",&n);

	printf("\nEnter the cost adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&d[i][j]);

	s1=omp_get_wtime();
	#pragma omp parallel for
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	e1=omp_get_wtime();
	t1=e1-s1;

	s2=omp_get_wtime();
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
			
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	e2=omp_get_wtime();
	t2=e2-s2;

	printf("\nthe shortest path matrix is shown below:\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%5d",d[i][j]);
				
			}
			printf("\n");
		}
	printf("\nTime taken for parallel execution=%lf",t1*100);
	printf("\nTime taken for sequential execution=%lf",t2*100);
}

int min(int x,int y)
{
	if(x<y)
		return x;
	else
		return y;
}
			