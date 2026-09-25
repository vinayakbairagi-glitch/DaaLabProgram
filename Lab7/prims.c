#include <stdio.h>
#define MAX 100
#define INF 999999
int main() {
    int V;
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int i, j;
    int edges = 0;
    int totalCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
    visited[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < V - 1) {
        int min = INF;
        int u = -1;
        int v = -1;
        for (i = 0; i < V; i++) {
            if (visited[i]) {
                for (j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u == -1) {
            printf("Graph is not connected.\n");
            return 0;
        }
        printf("%d -- %d = %d\n", u, v, min);
        totalCost += min;
        visited[v] = 1;
        edges++;
    }
    printf("\nMinimum Cost = %d\n", totalCost);
    return 0;
}