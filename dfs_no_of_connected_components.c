#include<stdio.h>
#define max 15
int v[max] ={0};
int label=0;


void dfs(int src, int a[max][max], int n)
{
	//printf("%d\t", src);
    v[src] = label;
    for(int i=0;i<n;i++)
        if(a[src][i] && v[i]==0)
            dfs(i,a,n);
}
int component(int a[max][max], int n)
{
    int i,j;
    

    for(i=0;i<n;i++)
    {    
        if(!v[i])
        {
            label++;
            dfs(i,a,n);
        }
    }
	return label;
}

void main()
{
    int i,j,a[max][max]={0},n;
    printf("enter the number of vertices\n");
   scanf("%d",&n);
    
   for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d", &a[i][j]);

    int res = component(a,n);
    printf("the number of components are %d\n", res);
	for(j=0;j<n;j++)
		printf("%d\t", v[j]);
}