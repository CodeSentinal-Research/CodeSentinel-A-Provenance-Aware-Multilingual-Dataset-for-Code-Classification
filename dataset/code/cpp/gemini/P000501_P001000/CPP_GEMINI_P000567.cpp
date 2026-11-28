#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> forest(m, std::vector<int>(n));
        std::vector<std::tuple<int, int, int>> trees;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                std::cin >> forest[r][c];
                if (forest[r][c] > 1) trees.push_back({forest[r][c], r, c});
            }
        }
        std::sort(trees.begin(), trees.end());
        auto bfs = [&](int sr, int sc, int tr, int tc) {
            if (sr == tr && sc == tc) return 0;
            std::queue<std::tuple<int, int, int>> q;
            std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, false));
            q.push({sr, sc, 0});
            vis[sr][sc] = true;
            int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
            while (!q.empty()) {
                auto [r, c, d] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] != 0 && !vis[nr][nc]) {
                        if (nr == tr && nc == tc) return d + 1;
                        vis[nr][nc] = true;
                        q.push({nr, nc, d + 1});
                    }
                }
            }
            return -1;
        };
        int total = 0, cur_r = 0, cur_c = 0;
        for (auto const& [val, tr, tc] : trees) {
            int step = bfs(cur_r, cur_c, tr, tc);
            if (step == -1) { std::cout << -1 << std::endl; return 0; }
            total += step;
            cur_r = tr; cur_c = tc;
        }
        std::cout << total << std::endl;
    }
    return 0;
}