#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::vector<int>> grid(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) std::cin >> grid[i][j];
        }
        std::queue<std::tuple<int, int, int, int>> q;
        std::vector<std::vector<std::vector<bool>>> vis(n, std::vector<std::vector<bool>>(n, std::vector<bool>(2, false)));
        q.push({0, 0, 0, 0});
        vis[0][0][0] = true;
        int ans = -1;
        while (!q.empty()) {
            auto [r, c, s, d] = q.front(); q.pop();
            if (s == 0 && r == n - 1 && c == n - 2) { ans = d; break; }
            if (s == 0) {
                if (c + 2 < n && grid[r][c + 2] == 0 && !vis[r][c + 1][0]) {
                    vis[r][c + 1][0] = true; q.push({r, c + 1, 0, d + 1});
                }
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r + 1][c][0]) {
                    vis[r + 1][c][0] = true; q.push({r + 1, c, 0, d + 1});
                }
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][1]) {
                    vis[r][c][1] = true; q.push({r, c, 1, d + 1});
                }
            } else {
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c + 1][1]) {
                    vis[r][c + 1][1] = true; q.push({r, c + 1, 1, d + 1});
                }
                if (r + 2 < n && grid[r + 2][c] == 0 && !vis[r + 1][c][1]) {
                    vis[r + 1][c][1] = true; q.push({r + 1, c, 1, d + 1});
                }
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][0]) {
                    vis[r][c][0] = true; q.push({r, c, 0, d + 1});
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}