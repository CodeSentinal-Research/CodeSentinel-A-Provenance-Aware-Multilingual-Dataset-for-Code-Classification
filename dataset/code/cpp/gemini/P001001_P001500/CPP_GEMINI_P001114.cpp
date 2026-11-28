#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::queue<std::tuple<int, int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j, 0});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        int minutes = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c, d] = q.front();
            q.pop();
            minutes = std::max(minutes, d);
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc, d + 1});
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};