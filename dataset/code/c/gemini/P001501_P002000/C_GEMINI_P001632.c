#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n, k;
    if (scanf("%d %d %d", &m, &n, &k) == 3) {
        int** p = (int**)malloc((m + 1) * sizeof(int*));
        for (int i = 0; i <= m; i++) p[i] = (int*)calloc(n + 1, sizeof(int));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                scanf("%d", &val);
                p[i + 1][j + 1] = val + p[i][j + 1] + p[i + 1][j] - p[i][j];
            }
        }

        int maxSide = 0;
        int limit = MIN(m, n);
        for (int side = 1; side <= limit; side++) {
            for (int i = 0; i <= m - side; i++) {
                for (int j = 0; j <= n - side; j++) {
                    int sum = p[i + side][j + side] - p[i][j + side] - p[i + side][j] + p[i][j];
                    if (sum <= k) maxSide = MAX(maxSide, side);
                }
            }
        }
        printf("%d\n", maxSide);
        for (int i = 0; i <= m; i++) free(p[i]);
        free(p);
    }
    return 0;
}