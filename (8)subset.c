(8)

#include <stdlib.h>
#include <stdio.h>

int s[10],x[10],d;

void subset(int m,int k,int r)
{
	int i;
    	x[k]=1;
    	if((m+s[k])==d)
    	{
        	for(i=1;i<=k;i++)
		{
            		if(x[i]==1)
                		printf("\t%d", s[i]);
		}
        	printf("\n");
    	}
    	else if (m+s[k]+s[k+1]<=d)
        	subset (m+s[k],k+1,r-s[k]);

    	if ((m+r-s[k]>=d) && (m+s[k+1]<=d))
    	{
        	x[k]=0;
        	subset (m,k+1,r-s[k]);
    	}
}

int main()
{
    	int n,sum=0,i;
    	printf("\n\tEnter the value of n:");
    	scanf("%d",&n);
    	printf("\n\tEnter the elements of the set in increasing order:");
    	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
    	printf("\n\tEnter the maximum value of the subset. ie: d=");
    	scanf("%d",&d);
    	for(i=1;i<=n;i++)
	{
        	sum+=s[i];
	}
    	if(sum <d||s[i]>d)
        	printf("\n\tSolution does not exist");
    	else
        	subset(0,1,sum);

    	return 0;
}

