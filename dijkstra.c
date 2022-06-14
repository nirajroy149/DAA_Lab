#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int minDistance(int V, int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[V], min_index = v;
    return min_index;
}

void printSolution(int V, int dist[]) {
    printf("\nVertex\t\tDistance from source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}
void dijkstra(int src, int V, int graph[V][V]) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(V, dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(V, dist);
}

void main()
{
    int V, source;
    printf("Enter no. of vertices of the graph: "), scanf("%d", &V);
    int graph[V][V];
    printf("Enter the matrix of pairs(if there's no direct path then enter '0'): ");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the source(in integer): "), scanf("%d", &source);
    dijkstra(source, V, graph);
}