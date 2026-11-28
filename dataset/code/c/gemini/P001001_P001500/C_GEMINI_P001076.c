#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        long long dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = (i == j) ? 0 : LLONG_MAX;
            }
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (w < dist[u][v]) dist[u][v] = w;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%lld%s", dist[i][j] == LLONG_MAX ? -1 : dist[i][j], (j == n - 1 ? "" : " "));
            }
            printf("\n");
        }
    }
    return 0;
}