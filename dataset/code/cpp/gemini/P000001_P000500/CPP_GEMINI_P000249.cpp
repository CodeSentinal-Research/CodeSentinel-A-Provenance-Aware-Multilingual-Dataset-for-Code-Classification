#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> multiplyMatrix(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
        if (A[0].size() != B.size()) return {};
        int r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
        std::vector<std::vector<int>> res(r1, std::vector<int>(c2, 0));

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return res;
    }
};