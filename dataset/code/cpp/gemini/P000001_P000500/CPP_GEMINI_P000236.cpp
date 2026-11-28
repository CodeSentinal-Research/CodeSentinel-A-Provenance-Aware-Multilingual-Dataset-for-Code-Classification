#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int findMaxValue(std::vector<std::vector<int>>& mat, int N) {
        std::vector<std::vector<int>> maxArr(N, std::vector<int>(N, 0));
        maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

        int maxV = mat[N - 1][N - 1];
        for (int j = N - 2; j >= 0; j--) {
            maxV = std::max(maxV, mat[N - 1][j]);
            maxArr[N - 1][j] = maxV;
        }

        maxV = mat[N - 1][N - 1];
        for (int i = N - 2; i >= 0; i--) {
            maxV = std::max(maxV, mat[i][N - 1]);
            maxArr[i][N - 1] = maxV;
        }

        int maxDiff = INT_MIN;

        for (int i = N - 2; i >= 0; i--) {
            for (int j = N - 2; j >= 0; j--) {
                maxDiff = std::max(maxDiff, maxArr[i + 1][j + 1] - mat[i][j]);
                maxArr[i][j] = std::max(mat[i][j], std::max(maxArr[i + 1][j], maxArr[i][j + 1]));
            }
        }
        return maxDiff;
    }
};