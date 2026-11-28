#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        std::vector<std::vector<int>> res(c, std::vector<int>(r));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};