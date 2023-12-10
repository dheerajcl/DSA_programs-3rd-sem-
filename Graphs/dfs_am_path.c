#include<stdio.h>
#define max 10
int length;
int p[max];
void read_graph(int a[max][max], int n)
{
	for(int i = 0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &a[i][j]);

}
void init_visit(int v[max], int n)
{
	for(int i=0;i<n;i++)
		v[i]=0;
}
int find_path(int s, int d, int n, int v[max], int a[max][max])//inc l++, store in p, if backtrack reduce length
{
	int u;
	v[s] = 1;
	for(int i = 0;i<n;i++)
	{
		if(a[s][i] && !v[i])
		{
			length++;
			p[length]=i;
			if((i==d) || find_path(i,d,n,v,a))
				return 1;	
		}
	}
	--length;
	return 0;
}
void path(int s, int d, int n, int v[max], int a[max][max])
{	
	int i,j,t;
	length = 0;
	init_visit(v,n);
	p[length] = s;
	t = find_path(s,d,n,v,a);
	if(t)
	{
		printf("path found\n");
		printf("length=%d\n", length);
		printf("vertices in path are:\n");
		for(i=0;i<=length;i++)
			printf("%d\t", p[i]);
	}
	else
	{
		printf("no path found\n");
	}
}
void main()
{
	int i,a[max][max]={0}, visited[max]={0},n;
	printf("enter the number of vertices\n");
	scanf("%d", &n);
	
	read_graph(a,n);
		
	printf("enter source and destination\n");
	int s,d;
	scanf("%d%d", &s,&d);
	path(s,d,n,visited,a);
}