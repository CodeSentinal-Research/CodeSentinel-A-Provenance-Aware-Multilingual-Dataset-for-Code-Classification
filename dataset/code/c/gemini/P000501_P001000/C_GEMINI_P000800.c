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
        int q; scanf("%d", &q);
        while (q--) {
            int r1, c1, r2, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            long long ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
            printf("%lld\n", ans);
        }
    }
    return 0;
}