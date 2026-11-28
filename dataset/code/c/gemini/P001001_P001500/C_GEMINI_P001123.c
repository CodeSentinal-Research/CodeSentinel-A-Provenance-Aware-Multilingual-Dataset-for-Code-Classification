#include <stdio.h>
#include <limits.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i == j) ? 0 : 1000000000;
        }
    }
    for (int i = 0; i < edgesSize; i++) {
        dist[edges[i][0]][edges[i][1]] = edges[i][2];
        dist[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int minReachable = 1000000000;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int reachable = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) reachable++;
        }
        if (reachable <= minReachable) {
            minReachable = reachable;
            ans = i;
        }
    }
    return ans;
}