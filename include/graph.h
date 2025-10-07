#ifndef GRAPH_H
#define GRAPH_H

#define INF 1000000
#define MAX_CITIES 100
#define MAX_NAME_LENGTH 50

void initializeGraph(int adj[MAX_CITIES][MAX_CITIES], int n);
void addEdge(int adj[MAX_CITIES][MAX_CITIES], int u, int v, int w);
void dijkstra(int adj[MAX_CITIES][MAX_CITIES], int n, int start, int end, char cityNames[MAX_CITIES][MAX_NAME_LENGTH]);

#endif


