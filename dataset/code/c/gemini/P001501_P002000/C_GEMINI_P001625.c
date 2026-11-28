#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        long long** p = (long long**)malloc(m * sizeof(long long*));
        for (int i = 0; i < m; i++) {
            p[i] = (long long*)malloc(n * sizeof(long long));
            for (int j = 0; j < n; j++) {
                long long val;
                scanf("%lld", &val);
                p[i][j] = val;
                if (i > 0) p[i][j] += p[i - 1][j];
                if (j > 0) p[i][j] += p[i][j - 1];
                if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
                printf("%lld%s", p[i][j], j == n - 1 ? "" : " ");
            }
            printf("\n");
        }
        for (int i = 0; i < m; i++) free(p[i]);
        free(p);
    }
    return 0;
}