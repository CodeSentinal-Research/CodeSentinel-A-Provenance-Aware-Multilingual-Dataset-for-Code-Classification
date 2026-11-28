#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> sumMatrix(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
        if (A.size() != B.size() || A[0].size() != B[0].size()) return {};
        int m = A.size(), n = A[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = A[i][j] + B[i][j];
            }
        }
        return res;
    }
};