#include<stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int vertices;

void DFS(int vertex){
    visited[vertex] = 1;
    printf("%d", vertex);

    for( int i = 0; i < vertices; i++){
        if( graph[vertex][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}

int main(){

    int edges , v1 , v2;

    printf("Enter the number of vertices :\n");
    scanf("%d",&vertices);
    printf("Enter the number of edges :\n");
    scanf("%d",&edges);

    for( int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            graph[i][j] = 0;
        }
        visited[i] = 0; 
    }

    printf("Enter the edges :\n");
    for( int i=0; i<edges; i++){
        scanf("%d %d",&v1 ,&v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    int start;
    printf("Enter the starting vertex :\n");
    scanf("%d",&start);

    printf("DFS TRAVERSAL \n");
    DFS(start);
}