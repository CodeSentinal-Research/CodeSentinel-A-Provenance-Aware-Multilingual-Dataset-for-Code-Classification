#include <vector>
#include <algorithm>

class Solution {
    int dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size() || grid[r][c] == 0) return 0;
        int gold = grid[r][c];
        grid[r][c] = 0;

        int maxSub = std::max({
            dfs(grid, r + 1, c),
            dfs(grid, r - 1, c),
            dfs(grid, r, c + 1),
            dfs(grid, r, c - 1)
        });

        grid[r][c] = gold;
        return gold + maxSub;
    }
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int maxGold = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    maxGold = std::max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
};