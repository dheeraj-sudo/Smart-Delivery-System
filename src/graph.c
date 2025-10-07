#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "../include/graph.h"

void initializeGraph(int adj[MAX_CITIES][MAX_CITIES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }
}

void addEdge(int adj[MAX_CITIES][MAX_CITIES], int u, int v, int w) {
    adj[u][v] = w;
    adj[v][u] = w;  // Assuming undirected graph
}

void dijkstra(int adj[MAX_CITIES][MAX_CITIES], int n, int start, int end, char cityNames[MAX_CITIES][MAX_NAME_LENGTH]) {
    int dist[MAX_CITIES];
    bool visited[MAX_CITIES];
    int prev[MAX_CITIES];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[end] == INF) {
        printf("No path exists between %s and %s\n", cityNames[start], cityNames[end]);
        return;
    }

    // Reconstruct path
    int path[MAX_CITIES];
    int count = 0;
    for (int v = end; v != -1; v = prev[v]) {
        path[count++] = v;
    }

    printf("Shortest path from %s to %s is: ", cityNames[start], cityNames[end]);
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", cityNames[path[i]]);
        if (i != 0) printf(" -> ");
    }
    printf("\nTotal distance: %d\n", dist[end]);
}
