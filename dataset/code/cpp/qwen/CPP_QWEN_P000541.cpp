#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1) fresh++;
        }
    }
    int mins = 0;
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    while (!q.empty() && fresh > 0) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; fresh--; q.push({nr, nc});
                }
            }
        }
        mins++;
    }
    return fresh == 0 ? mins : -1;
}

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
    cout << solve(grid) << endl;
    return 0;
}
