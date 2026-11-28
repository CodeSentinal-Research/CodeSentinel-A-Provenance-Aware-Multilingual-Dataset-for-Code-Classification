#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<int> temp;
        for (auto& row : matrix) {
            for (int x : row) temp.push_back(x);
        }
        std::sort(temp.begin(), temp.end());
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) matrix[i][j] = temp[idx++];
        }
        return matrix;
    }
};