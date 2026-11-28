#include <string.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = 1000000000;
    dist[src] = 0;

    for (int iter = 0; iter <= k; iter++) {
        int tmp[n];
        memcpy(tmp, dist, sizeof(dist));
        for (int i = 0; i < flightsSize; i++) {
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            if (dist[u] != 1000000000 && dist[u] + w < tmp[v]) {
                tmp[v] = dist[u] + w;
            }
        }
        memcpy(dist, tmp, sizeof(dist));
    }
    return dist[dst] == 1000000000 ? -1 : dist[dst];
}