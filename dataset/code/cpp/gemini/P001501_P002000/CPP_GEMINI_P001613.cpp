#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::vector<int>> p(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
            }
        }

        std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = std::max(0, i - k), c1 = std::max(0, j - k);
                int r2 = std::min(m - 1, i + k), c2 = std::min(n - 1, j + k);
                res[i][j] = p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1];
            }
        }
        return res;
    }
};