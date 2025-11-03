#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src , det , wei;
};

int main (){
    int V , E ;

    printf("\n Enter the number of Edges and Vertices :");
    scanf("%d %d", &V, &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("\n Enter the source destination and weight :");
    for(int i = 0; i < E; i++ ){
    scanf("%d %d %d", &edges[i].src , &edges[i].det , &edges[i].weight);
    }

    KruskalMST(edges , v , E);

}