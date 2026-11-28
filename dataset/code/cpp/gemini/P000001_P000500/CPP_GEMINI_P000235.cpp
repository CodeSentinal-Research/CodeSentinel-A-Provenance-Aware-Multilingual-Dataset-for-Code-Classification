#include <vector>

class Solution {
public:
    std::vector<int> printZigZag(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        for (size_t i = 0; i < matrix.size(); i++) {
            if (i % 2 == 0) {
                for (int x : matrix[i]) res.push_back(x);
            } else {
                for (int j = (int)matrix[i].size() - 1; j >= 0; j--) res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};