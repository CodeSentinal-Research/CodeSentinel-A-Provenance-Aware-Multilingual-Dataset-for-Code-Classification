#include <iostream>
#include <queue>
#include <unordered_set>
#include <cmath>
int main() {
    int x, y;
    if (std::cin >> x >> y) {
        x = std::abs(x); y = std::abs(y);
        std::queue<std::tuple<int, int, int>> q;
        q.push({0, 0, 0});
        int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
        std::vector<std::vector<bool>> vis(605, std::vector<bool>(605, false));
        vis[0 + 4][0 + 4] = true;
        int ans = 0;
        while (!q.empty()) {
            auto [r, c, d] = q.front(); q.pop();
            if (r == x && c == y) { ans = d; break; }
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= -2 && nr <= x + 2 && nc >= -2 && nc <= y + 2) {
                    if (!vis[nr + 4][nc + 4]) {
                        vis[nr + 4][nc + 4] = true;
                        q.push({nr, nc, d + 1});
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}