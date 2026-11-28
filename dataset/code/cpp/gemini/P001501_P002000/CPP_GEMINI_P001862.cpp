#include <vector>
#include <climits>

class Solution {
public:
    int optimalRoot(std::vector<int>& keys, std::vector<int>& freq) {
        int n = keys.size();
        std::vector<std::vector<int>> cost(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> rootChoice(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> w(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            w[i][i] = freq[i];
            cost[i][i] = freq[i];
            rootChoice[i][i] = i;
            for (int j = i + 1; j < n; j++) {
                w[i][j] = w[i][j - 1] + freq[j];
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                cost[i][j] = INT_MAX;
                for (int r = i; r <= j; r++) {
                    int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + w[i][j];
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        rootChoice[i][j] = r;
                    }
                }
            }
        }
        return keys[rootChoice[0][n - 1]];
    }
};