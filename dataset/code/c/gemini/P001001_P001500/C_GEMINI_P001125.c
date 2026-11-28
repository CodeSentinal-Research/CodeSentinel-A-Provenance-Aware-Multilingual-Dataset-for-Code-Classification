#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int dist[n + 1];
    bool vis[n + 1];
    for (int i = 1; i <= n; i++) { dist[i] = INT_MAX; vis[i] = false; }
    dist[k] = 0;

    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && (u == -1 || dist[i] < dist[u])) u = i;
        }
        if (u == -1 || dist[u] == INT_MAX) break;
        vis[u] = true;
        for (int i = 0; i < timesSize; i++) {
            if (times[i][0] == u) {
                int v = times[i][1], w = times[i][2];
                if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > max) max = dist[i];
    }
    return max;
}