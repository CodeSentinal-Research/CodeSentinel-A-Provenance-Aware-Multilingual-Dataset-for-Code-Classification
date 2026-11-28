#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int m = mat.size(), n = mat[0].size();
        std::vector<int> res;

        for (int d = 0; d < m + n - 1; d++) {
            std::vector<int> temp;
            int r = (d < n ? 0 : d - n + 1);
            int c = (d < n ? d : n - 1);

            while (r < m && c >= 0) {
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }

            if (d % 2 == 0) {
                std::reverse(temp.begin(), temp.end());
            }
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};