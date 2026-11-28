#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    // BFS state: (head_r, head_c, tail_r, tail_c)
    queue<tuple<int, int, int, int>> q;
    vector<vector<vector<vector<bool>>>> vis(n, vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n, false))));
    q.push({0, 1, 0, 0});
    vis[0][1][0][0] = true;
    int moves = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [hr, hc, tr, tc] = q.front(); q.pop();
            if (hr == n - 1 && hc == n - 1) {
                cout << moves << endl;
                return 0;
            }
            // Move right
            if (hc + 1 < n && tc + 1 < n && grid[hr][hc + 1] == 0 && grid[tr][tc + 1] == 0) {
                if (!vis[hr][hc + 1][tr][tc + 1]) {
                    vis[hr][hc + 1][tr][tc + 1] = true;
                    q.push({hr, hc + 1, tr, tc + 1});
                }
            }
            // Move down
            if (hr + 1 < n && tr + 1 < n && grid[hr + 1][hc] == 0 && grid[tr + 1][tc] == 0) {
                if (!vis[hr + 1][hc][tr + 1][tc]) {
                    vis[hr + 1][hc][tr + 1][tc] = true;
                    q.push({hr + 1, hc, tr + 1, tc});
                }
            }
            // Rotate clockwise (if horizontal)
            if (hr == tr && hc == tc + 1) {
                if (hr + 1 < n && grid[hr + 1][hc] == 0 && grid[hr + 1][tc] == 0) {
                    if (!vis[hr + 1][tc][tr][tc]) {
                        vis[hr + 1][tc][tr][tc] = true;
                        q.push({hr + 1, tc, tr, tc});
                    }
                }
            }
            // Rotate counter-clockwise (if vertical)
            if (hc == tc && hr == tr + 1) {
                if (hc + 1 < n && grid[hr][hc + 1] == 0 && grid[tr][hc + 1] == 0) {
                    if (!vis[tr][hc + 1][tr][tc]) {
                        vis[tr][hc + 1][tr][tc] = true;
                        q.push({tr, hc + 1, tr, tc});
                    }
                }
            }
        }
        moves++;
    }
    cout << -1 << endl;
    return 0;
}
