#include <vector>
class Solution {
public:
    std::vector<int> diagonalElements(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = matrix[i][i];
        return res;
    }
};
