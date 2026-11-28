#include <iostream>
#include <vector>
#include <queue>
struct Room { int r, c, d; };
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n));
        std::queue<Room> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                std::cin >> grid[r][c];
                if (grid[r][c] == 0) q.push({r, c, 0});
            }
        }
        int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            Room rm = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = rm.r + dr[i], nc = rm.c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = rm.d + 1;
                    q.push({nr, nc, rm.d + 1});
                }
            }
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                std::cout << grid[r][c] << (c == n - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
    return 0;
}