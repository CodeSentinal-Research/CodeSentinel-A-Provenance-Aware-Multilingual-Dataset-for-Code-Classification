#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int sr, int sc, int tr, int tc, vector<vector<int>>& forest) {
    if (sr == tr && sc == tc) return 0;
    int m = forest.size(), n = forest[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    int steps = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && forest[nr][nc] != 0) {
                    if (nr == tr && nc == tc) return steps + 1;
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> forest(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }
    vector<pair<int, pair<int, int>>> trees;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (forest[i][j] > 1) {
                trees.push_back({forest[i][j], {i, j}});
            }
        }
    }
    sort(trees.begin(), trees.end());
    int total_steps = 0;
    int cr = 0, cc = 0;
    for (auto& tree : trees) {
        int tr = tree.second.first, tc = tree.second.second;
        int steps = bfs(cr, cc, tr, tc, forest);
        if (steps == -1) {
            cout << -1 << endl;
            return 0;
        }
        total_steps += steps;
        cr = tr; cc = tc;
    }
    cout << total_steps << endl;
    return 0;
}
