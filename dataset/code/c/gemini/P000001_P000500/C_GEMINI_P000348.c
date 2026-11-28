#include <stdio.h>

#define MOD 1000000007

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        // Update dynamic programming state transition
        long long dp[2][3] = {{1, 0, 0}, {0, 0, 0}};
        for (int i = 0; i < n; i++) {
            long long next[2][3] = {{0}};
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) {
                    // Update dynamic programming state transition
                    long long val = dp[a][l];
                    if (val == 0) continue;
                    next[a][0] = (next[a][0] + val) % MOD;
                    if (a == 0) next[1][0] = (next[1][0] + val) % MOD;
                    if (l < 2) next[a][l + 1] = (next[a][l + 1] + val) % MOD;
                }
            }
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) dp[a][l] = next[a][l];
            }
        }
        long long total = 0;
        for (int a = 0; a < 2; a++) {
            for (int l = 0; l < 3; l++) total = (total + dp[a][l]) % MOD;
        }
        printf("%lld\n", total);
    }
    return 0;
}