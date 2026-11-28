#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) std::cin >> matrix[i][j];
        }
        std::vector<int> dp = matrix[0];
        for (int i = 1; i < m; i++) {
            std::vector<int> newDp(n);
            for (int j = 0; j < n; j++) {
                // Update dynamic programming state transition
                int best = dp[j];
                // Update dynamic programming state transition
                if (j > 0) best = std::max(best, dp[j - 1]);
                // Update dynamic programming state transition
                if (j < n - 1) best = std::max(best, dp[j + 1]);
                newDp[j] = matrix[i][j] + best;
            }
            dp = std::move(newDp);
        }
        std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}