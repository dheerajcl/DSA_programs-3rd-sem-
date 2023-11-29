#include<stdio.h>
#define max 10
void dfs(int cv, int adj[max][max], int v[max], int n)
{
	int x;
	printf("%d", cv);
	v[cv] = 1;
	for(int i=0;i<n;i++)
	{
		if(adj[cv][i] && !v[i])
			dfs(i,adj,v,n);
	}
}

void read_graph(int adj[max][max], int n)
{
	printf("enter the matrix\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &adj[i][j]);
}
int main()
{

	int adj[max][max]={0},adj_copy[max][max]={0};
	int visited[max]={0};
	int n,i;	//no. of vertex
	

	printf("enter the value of n\n");
	scanf("%d",&n);
	int cv=0;
	
	read_graph(adj,n);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(adj[i][j]==1)
				adj_copy[i][j] = adj_copy[j][i] = 1;
	
	
	dfs(0,adj_copy,visited,n);
	for(i=0;i<n;i++)
		if(!visited[i]) break;
 
	if (i<n)
		printf("not weakly connected\n");
	else
		printf("weakly connected\n");
	
return 0;
}