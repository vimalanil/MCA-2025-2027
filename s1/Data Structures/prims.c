#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int V;

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int **graph) {
    printf("\n--- Minimum Spanning Tree Edges ---\n");
    printf("Edge \tWeight\n");
    int total_cost = 0;
    
    for (int i = 1; i < V; i++) {
        int weight = graph[i][parent[i]];
        printf("%d - %d \t%d\n", parent[i], i, weight);
        total_cost += weight;
    }
    printf("\nTotal Minimum Cost: %d\n", total_cost);
}

void primMST(int **graph) {
    int parent[V]; 
    int key[V];    
    int mstSet[V]; 

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0; 
    }

    key[0] = 0;     
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        
        if (u == -1) break; 

        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    printf("Enter the number of vertices (N): "); // Number of vertices
    if (scanf("%d", &V) != 1 || V <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("\nEnter the adjacency matrix (weights):\n");
    printf("Use 0 for edges that do not exist.\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Weight of edge (%d, %d): ", i, j);
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid input.\n");
                for (int k = 0; k <= i; k++) {
                    free(graph[k]);
                }
                free(graph);
                return 1;
            }
            if (i == j) graph[i][j] = 0;
        }
    }

    primMST(graph);

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}