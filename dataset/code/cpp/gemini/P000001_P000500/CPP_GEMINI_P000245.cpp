#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> lowerTriangular(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        return matrix;
    }
};