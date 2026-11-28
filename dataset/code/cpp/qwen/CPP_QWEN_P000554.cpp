#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n, er, ec;
    cin >> m >> n >> er >> ec;
    vector<string> maze(m);
    for (int i = 0; i < m; i++) cin >> maze[i];
    if ((er == 0 || er == m - 1 || ec == 0 || ec == n - 1) && !(er == 0 && ec == 0)) {
        cout << 0 << endl;
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({er, ec});
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vis[er][ec] = true;
    int steps = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && maze[nr][nc] == '.') {
                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                        cout << steps + 1 << endl;
                        return 0;
                    }
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        steps++;
    }
    cout << -1 << endl;
    return 0;
}
