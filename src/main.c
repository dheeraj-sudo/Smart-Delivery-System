#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/graph.h"

#define MAX_CITIES 100
#define MAX_NAME_LENGTH 50

int main() {
    int n, m;
    char cityNames[MAX_CITIES][MAX_NAME_LENGTH];
    int adj[MAX_CITIES][MAX_CITIES];

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter name of each city:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", cityNames[i]);
    }

    initializeGraph(adj, n);

    printf("Enter number of roads: ");
    scanf("%d", &m);

    printf("Enter road details (City1 City2 Distance):\n");
    for (int i = 0; i < m; i++) {
        char city1[MAX_NAME_LENGTH], city2[MAX_NAME_LENGTH];
        int dist;
        scanf("%s %s %d", city1, city2, &dist);

        int u = -1, v = -1;
        for (int j = 0; j < n; j++) {
            if (strcmp(cityNames[j], city1) == 0) u = j;
            if (strcmp(cityNames[j], city2) == 0) v = j;
        }

        if (u != -1 && v != -1) {
            addEdge(adj, u, v, dist);
        } else {
            printf("Error: Invalid city name.\n");
        }
    }

    char start[MAX_NAME_LENGTH], end[MAX_NAME_LENGTH];
    printf("Enter start city: ");
    scanf("%s", start);
    printf("Enter destination city: ");
    scanf("%s", end);

    int startIndex = -1, endIndex = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(cityNames[i], start) == 0) startIndex = i;
        if (strcmp(cityNames[i], end) == 0) endIndex = i;
    }

    if (startIndex == -1 || endIndex == -1) {
        printf("Invalid city name entered.\n");
        return 1;
    }

    dijkstra(adj, n, startIndex, endIndex, cityNames);

    return 0;
}
