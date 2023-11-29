#include<stdio.h>
#include<stdlib.h>

void read_graph(int g[7][7],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter the value of g[%d][%d]: ",i,j);
            scanf("%d",&g[i][j]);
        }
    }
}
void display(int g[7][7],int n)
{
    printf("The adjacency matrix is: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}
int inDegree(int g[7][7],int n,int v)
{
    int in_degree=0;
    for(int i=0;i<n;i++)
    {
        if(g[i][v]==1)
        {
            in_degree++;
        }
    }
    return in_degree;
}
int outDegree(int g[7][7],int n,int v)
{
    int out_degree=0;
    for(int i=0;i<n;i++)
    {
        if(g[v][i]==1)
        {
            out_degree++;
        }
    }
    return out_degree;
}
int main()
{
    int n,v;
    printf("enter the number of vertices: ");
    scanf("%d",&n);
    int g[n][n];
    printf("enter the adjacency matrix: \n");
    read_graph(g,n);
    display(g,n);
    printf("enter the vertex you want the in degree and out degree of: ");
    scanf("%d",&v);
    int in_degree=0;
    int out_degree=0;
    in_degree=inDegree(g,n,v);
    out_degree=outDegree(g,n,v);
    printf("The in degree of %d is %d\n",v,in_degree);
    printf("The out degree of %d is %d\n",v,out_degree);
    return 0;
}
