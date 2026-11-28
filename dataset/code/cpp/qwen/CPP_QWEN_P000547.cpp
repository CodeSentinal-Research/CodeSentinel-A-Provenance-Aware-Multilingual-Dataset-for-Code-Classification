#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
    vector<vector<int>> fire(m, vector<int>(n, 1e9));
    queue<pair<int, int>> fq;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) { fire[i][j] = 0; fq.push({i, j}); }
        }
    }
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    while (!fq.empty()) {
        auto [r, c] = fq.front(); fq.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && fire[nr][nc] == 1e9) {
                fire[nr][nc] = fire[r][c] + 1; fq.push({nr, nc});
            }
        }
    }
    int l = 0, r = m * n, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        vector<vector<int>> vis(m, vector<int>(n, 1e9));
        queue<pair<int, int>> q;
        if (fire[0][0] > mid) { q.push({0, 0}); vis[0][0] = mid; }
        bool ok = false;
        while (!q.empty()) {
            auto [r_c, c_c] = q.front(); q.pop();
            if (r_c == m - 1 && c_c == n - 1) { ok = true; break; }
            for (int d = 0; d < 4; d++) {
                int nr = r_c + dx[d], nc = c_c + dy[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    int ntime = vis[r_c][c_c] + 1;
                    if (ntime < fire[nr][nc] && ntime < vis[nr][nc]) {
                        vis[nr][nc] = ntime; q.push({nr, nc});
                    }
                }
            }
        }
        if (ok) { ans = mid; l = mid + 1; } else r = mid - 1;
    }
    return ans == m * n ? 1e9 : ans;
}

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
    cout << solve(grid) << endl;
    return 0;
}
