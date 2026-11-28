#include <iostream>
#include <vector>
#include <string>
#include <queue>
struct Cell { int r, c, d; };
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::string> maze(m);
        for (int i = 0; i < m; i++) std::cin >> maze[i];
        int er, ec;
        std::cin >> er >> ec;
        std::queue<Cell> q;
        std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, false));
        q.push({er, ec, 0});
        vis[er][ec] = true;
        int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
        int ans = -1;
        while (!q.empty()) {
            Cell cur = q.front(); q.pop();
            if ((cur.r != er || cur.c != ec) && (cur.r == 0 || cur.r == m - 1 || cur.c == 0 || cur.c == n - 1)) {
                ans = cur.d; break;
            }
            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i], nc = cur.c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.' && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc, cur.d + 1});
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}