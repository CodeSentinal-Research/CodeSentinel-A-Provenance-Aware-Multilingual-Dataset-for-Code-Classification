#include <vector>
#include <algorithm>
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), side = 0;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '1') {
                    dp[i][j] = (i == 0 || j == 0) ? 1 :
                        std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    side = std::max(side, dp[i][j]);
                }
        return side * side;
    }
};
