#include<stdio.h>
#define max 10

int dfs(int s, int a[max][max], int v[max],int n, int p)
{
	v[s] = 1;
	for(int i=0;i<n;i++)
	{
		if(a[s][i])
		{
			if(i!=p)
			{
				if(v[s])
					return 1;
				int k = dfs(i,a,v,n,s);
				if(k)
					return 0;	
			}
		}
	}	

return 0;
}

int main()
{
	int n, adj[max][max]={0}, v[max]={0}, p=-1;
	
	printf("enter the number of vertices\n");
	scanf("%d", &n);
	printf("enter the matrix\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &adj[i][j]);
	int res = dfs(0,adj,v,n,p);
	if(res)
		printf("cycle present\n");
	else
		printf("cycle not present\n");

return 0;
}