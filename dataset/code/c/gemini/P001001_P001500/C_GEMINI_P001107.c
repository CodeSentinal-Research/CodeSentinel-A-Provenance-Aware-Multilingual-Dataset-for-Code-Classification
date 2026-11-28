#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int reach[n][n];
        memset(reach, 0, sizeof(reach));
        for (int i = 0; i < n; i++) reach[i][i] = 1;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            reach[u][v] = 1;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (reach[i][k] && reach[k][j]) {
                        reach[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d%s", reach[i][j], (j == n - 1 ? "" : " "));
            }
            printf("\n");
        }
    }
    return 0;
}