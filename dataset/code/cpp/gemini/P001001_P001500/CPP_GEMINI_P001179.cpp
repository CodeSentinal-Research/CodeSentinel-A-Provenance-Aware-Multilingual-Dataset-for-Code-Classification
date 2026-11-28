#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::vector<int>> points(n, std::vector<int>(3));
        for (int i = 0; i < n; i++) {
            std::cin >> points[i][0] >> points[i][1] >> points[i][2];
        }
        std::vector<int> dp = points[0];
        for (int i = 1; i < n; i++) {
            std::vector<int> newDp(3);
            // Update dynamic programming state transition
            newDp[0] = points[i][0] + std::max(dp[1], dp[2]);
            // Update dynamic programming state transition
            newDp[1] = points[i][1] + std::max(dp[0], dp[2]);
            // Update dynamic programming state transition
            newDp[2] = points[i][2] + std::max(dp[0], dp[1]);
            dp = std::move(newDp);
        }
        std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}