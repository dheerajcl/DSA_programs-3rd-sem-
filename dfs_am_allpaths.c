#include <stdio.h>
#include <stdlib.h>
int a[10][10], n, p = 0;
void read_ad_mat()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void printall(int u, int d, int visited[10], int path[10])
{
    visited[u] = 1;
    path[p] = u;
    p++;
    if (u == d)
    {
        for (int i = 0; i < p; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else
    {
        for (int v = 0; v < n; v++)
            if (a[u][v] == 1 && visited[v] == 0)
            {
                printall(v, d, visited, path);
            }
    }
    p--;
    visited[u] = 0;
}
void printpath(int s, int d)
{
    int visited[10];
    int path[10];
    int p = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printall(s, d, visited, path);
}
int main()
{
    int i, so, de;
    printf("enter the number of nodes\n");
    scanf("%d", &n);
    printf("enter the adjacency list\n");
    read_ad_mat();
    printf("enter the source and destination\n");
    scanf("%d%d", &so, &de);
    printpath(so, de);
}