#include <stdio.h>

#define MOD 1000000007LL

void matMul(int n, long long a[n][n], long long b[n][n], long long res[n][n]) {
    long long temp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) temp[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) res[i][j] = temp[i][j];
    }
}

int main() {
    int n;
    long long p;
    if (scanf("%d %lld", &n, &p) == 2 && n > 0) {
        long long base[n][n], res[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &base[i][j]);
                res[i][j] = (i == j) ? 1 : 0;
            }
        }
        while (p > 0) {
            // If current bit is set, multiply base into result
            if (p % 2 == 1) matMul(n, res, base, res);
            matMul(n, base, base, base);
            p /= 2;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%lld%s", res[i][j], (j == n - 1 ? "" : " "));
            }
            printf("\n");
        }
    }
    return 0;
}