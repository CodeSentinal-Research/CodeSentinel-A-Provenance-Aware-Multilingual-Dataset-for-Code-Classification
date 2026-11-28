#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
        int r1 = mat1.size(), c1 = mat1[0].size();
        int c2 = mat2[0].size();
        std::vector<std::vector<int>> res(r1, std::vector<int>(c2, 0));
        for (int i = 0; i < r1; i++) {
            for (int k = 0; k < c1; k++) {
                if (mat1[i][k] != 0) {
                    for (int j = 0; j < c2; j++) {
                        if (mat2[k][j] != 0) {
                            res[i][j] += mat1[i][k] * mat2[k][j];
                        }
                    }
                }
            }
        }
        return res;
    }
};