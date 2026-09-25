#include <stdio.h>
#define MAX 100
struct Edge {
    int source;
    int destination;
    int weight;
};
int parent[MAX];
int find(int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    return find(parent[vertex]);
}
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootV] = rootU;
}
int main() {
    int V, E;
    int i, j;
    int edgeCount = 0;
    int totalCost = 0;
    struct Edge edges[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter source, destination and weight:\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].source,
              &edges[i].destination,
              &edges[i].weight);
    }
    for (i = 0; i < V; i++) {
        parent[i] = i;
    }
    for (i = 0; i < E - 1; i++) {
        for (j = i + 1; j < E; j++) {
            if (edges[i].weight > edges[j].weight) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        if (find(u) != find(v)) {
            printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);
            totalCost += edges[i].weight;
            unionSet(u, v);
            edgeCount++;
        }
    }
    printf("\nMinimum Cost = %d\n", totalCost);
    return 0;
}