#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        Edge* edges = (Edge*)malloc(m * sizeof(Edge));
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        int src;
        scanf("%d", &src);
        long long* dist = (long long*)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) dist[i] = LLONG_MAX;
        dist[src] = 0;

        for (int iter = 0; iter < n - 1; iter++) {
            for (int i = 0; i < m; i++) {
                int u = edges[i].u, v = edges[i].v, w = edges[i].w;
                if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        bool negCycle = false;
        for (int i = 0; i < m; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                negCycle = true;
                break;
            }
        }

        if (negCycle) {
            printf("NEGATIVE CYCLE\n");
        } else {
            for (int i = 0; i < n; i++) {
                printf("%lld%s", dist[i] == LLONG_MAX ? -1 : dist[i], (i == n - 1 ? "" : " "));
            }
            printf("\n");
        }
        free(edges);
        free(dist);
    }
    return 0;
}