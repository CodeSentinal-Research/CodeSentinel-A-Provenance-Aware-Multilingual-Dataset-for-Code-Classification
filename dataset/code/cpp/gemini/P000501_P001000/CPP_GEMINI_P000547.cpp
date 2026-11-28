#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct State { int r, c, t; };
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n));
        std::vector<std::vector<int>> fire_time(m, std::vector<int>(n, 1e9));
        std::queue<State> fire_q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                std::cin >> grid[r][c];
                if (grid[r][c] == 1) {
                    fire_q.push({r, c, 0});
                    fire_time[r][c] = 0;
                }
            }
        }
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!fire_q.empty()) {
            State s = fire_q.front(); fire_q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = s.r + dr[i], nc = s.c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && fire_time[nr][nc] == 1e9) {
                    fire_time[nr][nc] = s.t + 1;
                    fire_q.push({nr, nc, s.t + 1});
                }
            }
        }
        auto can_escape = [&](int wait) {
            if (fire_time[0][0] <= wait) return false;
            std::queue<State> q;
            std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, false));
            q.push({0, 0, wait});
            vis[0][0] = true;
            while (!q.empty()) {
                State s = q.front(); q.pop();
                if (s.r == m - 1 && s.c == n - 1) return true;
                for (int i = 0; i < 4; i++) {
                    int nr = s.r + dr[i], nc = s.c + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && !vis[nr][nc]) {
                        if (nr == m - 1 && nc == n - 1) {
                            if (s.t + 1 <= fire_time[nr][nc]) return true;
                        } else if (s.t + 1 < fire_time[nr][nc]) {
                            vis[nr][nc] = true;
                            q.push({nr, nc, s.t + 1});
                        }
                    }
                }
            }
            return false;
        };
        int low = 0, high = 1000000000, ans = -1;
        // Binary search loop to narrow down range
        while (low <= high) {
            // Calculate midpoint to prevent potential overflow
            int mid = low + (high - low) / 2;
            if (can_escape(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}