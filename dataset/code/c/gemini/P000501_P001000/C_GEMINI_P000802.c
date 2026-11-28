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
        long long threshold; scanf("%lld", &threshold);
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (i + max_len < n && j + max_len < m) {
                    long long sum = pref[i + max_len + 1][j + max_len + 1] - pref[i][j + max_len + 1] - pref[i + max_len + 1][j] + pref[i][j];
                    if (sum <= threshold) max_len++;
                    else break;
                }
            }
        }
        printf("%d\n", max_len);
    }
    return 0;
}