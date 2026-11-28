#include <vector>

class Solution {
public:
    std::vector<int> BoundaryElements(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};