#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int memo[105][105];
int suffix[105];

// Solves 'Stone Game II' by applying optimal Dynamic Programming logic.
int dp_solve(int i, int m, int n) {
    if (i >= n) return 0;
    if (i + 2 * m >= n) return suffix[i];
    if (memo[i][m] > 0) return memo[i][m];

    int res = 0;
    for (int x = 1; x <= 2 * m; x++) {
        res = MAX(res, suffix[i] - dp_solve(i + x, MAX(m, x), n));
    }
    return memo[i][m] = res;
}

int stoneGameII(int* piles, int pilesSize) {
    memset(memo, 0, sizeof(memo));
    suffix[pilesSize] = 0;
    for (int i = pilesSize - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
    return dp_solve(0, 1, pilesSize);
}