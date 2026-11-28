#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int memo[105][105];
int suffix[105];
int N;

int dp(int i, int m) {
    if (i >= N) return 0;
    if (i + 2 * m >= N) return suffix[i];
    if (memo[i][m] != -1) return memo[i][m];

    int res = 0;
    for (int x = 1; x <= 2 * m; x++) {
        res = MAX(res, suffix[i] - dp(i + x, MAX(m, x)));
    }
    return memo[i][m] = res;
}

int stoneGameII(int* piles, int pilesSize) {
    N = pilesSize;
    suffix[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + piles[i];
    }
    memset(memo, -1, sizeof(memo));
    return dp(0, 1);
}