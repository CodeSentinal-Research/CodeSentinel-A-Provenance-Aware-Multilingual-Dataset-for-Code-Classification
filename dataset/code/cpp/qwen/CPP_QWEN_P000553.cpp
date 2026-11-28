#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    map<pair<int, int>, int> dist;
    dist[{0, 0}] = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == n - 1 && c == n - 1) {
            cout << dist[{r, c}] << endl;
            return 0;
        }
        int next_r = r + dx[board[r][c]];
        int next_c = c + dy[board[r][c]];
        if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) {
            if (dist.find({next_r, next_c}) == dist.end()) {
                dist[{next_r, next_c}] = dist[{r, c}] + 1;
                q.push({next_r, next_c});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
