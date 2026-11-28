#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int maximumSumRectangle(int R, int C, std::vector<std::vector<int>>& M) {
        int maxSum = INT_MIN;

        for (int l = 0; l < C; l++) {
            std::vector<int> temp(R, 0);
            for (int r = l; r < C; r++) {
                for (int i = 0; i < R; i++) {
                    temp[i] += M[i][r];
                }

                int cur = temp[0], maxSoFar = temp[0];
                for (int i = 1; i < R; i++) {
                    cur = std::max(temp[i], cur + temp[i]);
                    maxSoFar = std::max(maxSoFar, cur);
                }

                maxSum = std::max(maxSum, maxSoFar);
            }
        }
        return maxSum;
    }
};