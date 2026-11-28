#include <vector>
#include <map>

class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        std::map<std::vector<int>, int> map;
        for (const auto& row : grid) map[row]++;

        int n = grid.size();
        int ans = 0;

        for (int c = 0; c < n; c++) {
            std::vector<int> col(n);
            for (int r = 0; r < n; r++) col[r] = grid[r][c];
            ans += map[col];
        }
        return ans;
    }
};