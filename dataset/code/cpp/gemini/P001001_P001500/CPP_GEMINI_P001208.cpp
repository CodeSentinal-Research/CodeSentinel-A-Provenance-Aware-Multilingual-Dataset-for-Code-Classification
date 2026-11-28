#include <vector>
#include <algorithm>

class Solution {
    std::vector<std::vector<int>> memo;
    std::vector<int> suffix;

    int dp(int i, int m, int n) {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffix[i];
        if (memo[i][m] > 0) return memo[i][m];

        int res = 0;
        for (int x = 1; x <= 2 * m; x++) {
            res = std::max(res, suffix[i] - dp(i + x, std::max(m, x), n));
        }
        return memo[i][m] = res;
    }
public:
    int stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        suffix.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
        memo.assign(n + 1, std::vector<int>(n + 1, 0));
        return dp(0, 1, n);
    }
};