#include <stdio.h>
long long pref[1005][1005];
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long x; scanf("%lld", &x);
                pref[i][j] = x;
                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%lld%s", pref[i][j], j == m - 1 ? "" : " ");
            }
            printf("\n");
        }
    }
    return 0;
}