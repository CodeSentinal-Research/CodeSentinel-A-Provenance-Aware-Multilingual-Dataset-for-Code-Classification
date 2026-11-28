#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        std::queue<std::tuple<int, int, int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [r, c, d] = q.front();
            q.pop();
            if (r == n - 1 && c == n - 1) return d;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc, d + 1});
                }
            }
        }
        return -1;
    }
};