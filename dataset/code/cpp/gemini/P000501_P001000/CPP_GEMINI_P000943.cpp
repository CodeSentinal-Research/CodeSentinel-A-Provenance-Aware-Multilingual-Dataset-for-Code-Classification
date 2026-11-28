#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

class Solution {
    int memo[105][105];
    int suffix[105];
    int n;

    int dp(int i, int m) {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffix[i];
        if (memo[i][m] != -1) return memo[i][m];

        int res = 0;
        for (int x = 1; x <= 2 * m; x++) {
            res = std::max(res, suffix[i] - dp(i + x, std::max(m, x)));
        }
        return memo[i][m] = res;
    }

public:
    int stoneGameII(std::vector<int>& piles) {
        n = piles.size();
        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        std::memset(memo, -1, sizeof(memo));
        return dp(0, 1);
    }
};