#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> mat(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) std::cin >> mat[i][j];
        }

        int maxSum = INT_MIN;

        for (int left = 0; left < n; left++) {
            std::vector<int> rowSum(m, 0);
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) rowSum[i] += mat[i][right];

                int curMax = rowSum[0];
                int curSum = 0;
                for (int x : rowSum) {
                    curSum = std::max(x, curSum + x);
                    curMax = std::max(curMax, curSum);
                }
                maxSum = std::max(maxSum, curMax);
            }
        }
        std::cout << maxSum << "\n";
    }
    return 0;
}