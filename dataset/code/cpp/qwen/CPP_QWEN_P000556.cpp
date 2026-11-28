#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(m, vector<int>(n, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    dp[0][0] = 1;
    pq.push({1, {0, 0}});
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!pq.empty()) {
        auto [cells, pos] = pq.top(); pq.pop();
        int r = pos.first, c = pos.second;
        if (r == m - 1 && c == n - 1) {
            cout << cells << endl;
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            for (int step = 1; step <= grid[r][c]; step++) {
                int nr = r + dx[d] * step;
                int nc = c + dy[d] * step;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && dp[nr][nc] > cells + 1) {
                    dp[nr][nc] = cells + 1;
                    pq.push({dp[nr][nc], {nr, nc}});
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
