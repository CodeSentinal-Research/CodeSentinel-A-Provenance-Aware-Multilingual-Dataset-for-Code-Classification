#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> upperTriangular(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                matrix[i][j] = 0;
            }
        }
        return matrix;
    }
};