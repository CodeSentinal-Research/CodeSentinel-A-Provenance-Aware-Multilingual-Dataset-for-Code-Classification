#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) std::cin >> grid[i][j];
        }
        if (m == 1 && n == 1) { std::cout << 1 << std::endl; return 0; }
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, 1e9));
        dist[0][0] = 1;
        std::vector<int> max_r(m, 0), max_c(n, 0);
        std::queue<std::pair<int, int>> q;
        q.push({0, 0});
        int ans = -1;
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            int d = dist[r][c];
            int k = grid[r][c];
            int start_c = std::max(c + 1, max_r[r] + 1);
            int end_c = std::min(c + k, n - 1);
            for (int nc = start_c; nc <= end_c; nc++) {
                if (dist[r][nc] == 1e9) {
                    dist[r][nc] = d + 1;
                    if (r == m - 1 && nc == n - 1) { ans = d + 1; break; }
                    q.push({r, nc});
                }
            }
            if (ans != -1) break;
            max_r[r] = std::max(max_r[r], end_c);
            int start_r = std::max(r + 1, max_c[c] + 1);
            int end_r = std::min(r + k, m - 1);
            for (int nr = start_r; nr <= end_r; nr++) {
                if (dist[nr][c] == 1e9) {
                    dist[nr][c] = d + 1;
                    if (nr == m - 1 && c == n - 1) { ans = d + 1; break; }
                    q.push({nr, c});
                }
            }
            if (ans != -1) break;
            max_c[c] = std::max(max_c[c], end_r);
        }
        std::cout << (dist[m - 1][n - 1] != 1e9 ? dist[m - 1][n - 1] : -1) << std::endl;
    }
    return 0;
}