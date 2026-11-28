#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct Orange { int r, c, d; };
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n));
        std::queue<Orange> q;
        int fresh = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                std::cin >> grid[r][c];
                if (grid[r][c] == 2) q.push({r, c, 0});
                else if (grid[r][c] == 1) fresh++;
            }
        }
        int mins = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            Orange o = q.front(); q.pop();
            mins = std::max(mins, o.d);
            for (int i = 0; i < 4; i++) {
                int nr = o.r + dr[i], nc = o.c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc, o.d + 1});
                }
            }
        }
        std::cout << (fresh == 0 ? mins : -1) << std::endl;
    }
    return 0;
}