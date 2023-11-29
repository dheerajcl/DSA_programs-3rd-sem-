#include<stdio.h>
#include<stdlib.h>

void bfs(int q[],int visited[],int f,int r,int adj[10][10],int n){

    int x;
    while(f <= r){
        x = q[f++];
        printf("%d ",x);

        for(int i=0;i<n;i++){
            if(adj[x][i] && !visited[i]){
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }
}


void read_graph(int g[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
}

void display(int g[10][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}



int main(){
    int q[10];
    int visited[10];

    for(int i=0;i<10;i++){
        visited[i] = 0;
    }

    int f = 0;
    int r = -1;

    int v;
    printf("Enter the number of vertices : \n");
    scanf("%d",&v);
    int graph[10][10];
    printf("Enter the Adjacency matrix : \n");
    read_graph(graph,v);
    //display(graph,v);

    q[++r] = 0;
    visited[0] = 1;

    printf("\nBFS traversal :-- ");
    bfs(q,visited,f,r,graph,v);

}