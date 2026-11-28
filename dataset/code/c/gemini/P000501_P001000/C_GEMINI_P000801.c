#include <stdio.h>
long long pref[1005][1005];
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long val; scanf("%lld", &val);
                pref[i + 1][j + 1] = val + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        int k; scanf("%d", &k);
        for (int i = 0; i < n; i++) {
            int r1 = (i - k > 0) ? i - k : 0;
            int r2 = (i + k < n - 1) ? i + k : n - 1;
            for (int j = 0; j < m; j++) {
                int c1 = (j - k > 0) ? j - k : 0;
                int c2 = (j + k < m - 1) ? j + k : m - 1;
                long long ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                printf("%lld%s", ans, j == m - 1 ? "" : " ");
            }
            printf("\n");
        }
    }
    return 0;
}