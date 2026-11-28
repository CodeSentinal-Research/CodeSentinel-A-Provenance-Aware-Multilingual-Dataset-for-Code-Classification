#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int maxSum = INT_MIN;

        for (int l = 0; l < n; l++) {
            std::vector<int> rowSum(m, 0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) rowSum[i] += matrix[i][r];

                for (int i = 0; i < m; i++) {
                    int cur = 0;
                    for (int j = i; j < m; j++) {
                        cur += rowSum[j];
                        if (cur <= k) maxSum = std::max(maxSum, cur);
                    }
                }
            }
        }
        return maxSum;
    }
};