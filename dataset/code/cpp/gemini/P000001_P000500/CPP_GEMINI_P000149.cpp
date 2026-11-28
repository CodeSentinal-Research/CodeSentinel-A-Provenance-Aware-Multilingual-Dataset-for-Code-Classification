#include <vector>

class Solution {
public:
    int rowWithMax1s(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return -1;
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n - 1;
        int maxRow = -1;

        while (r < m && c >= 0) {
            if (matrix[r][c] == 1) {
                maxRow = r;
                c--;
            } else {
                r++;
            }
        }
        return maxRow;
    }
};