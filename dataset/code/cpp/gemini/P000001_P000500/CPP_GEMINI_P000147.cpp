#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> diagonalElements(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int n = std::min(matrix.size(), matrix[0].size());
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = matrix[i][i];
        return res;
    }
};