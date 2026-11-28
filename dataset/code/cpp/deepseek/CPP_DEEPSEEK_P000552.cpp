#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return;
    int n = grid[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 0)
                q.push({i, j});

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i > 0 && grid[i - 1][j] > 0) {
            grid[i - 1][j] = min(grid[i - 1][j], grid[i][j] + 1);
            q.push({i - 1, j});
        }
        if (j > 0 && grid[i][j - 1] > 0) {
            grid[i][j - 1] = min(grid[i][j - 1], grid[i][j] + 1);
            q.push({i, j - 1});
        }
        if (i < m - 1 && grid[i + 1][j] > 0) {
            grid[i + 1][j] = min(grid[i + 1][j], grid[i][j] + 1);
            q.push({i + 1, j});
        }
        if (j < n - 1 && grid[i][j + 1] > 0) {
            grid[i][j + 1] = min(grid[i][j + 1], grid[i][j] + 1);
            q.push({i, j + 1});
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    solve(grid);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}