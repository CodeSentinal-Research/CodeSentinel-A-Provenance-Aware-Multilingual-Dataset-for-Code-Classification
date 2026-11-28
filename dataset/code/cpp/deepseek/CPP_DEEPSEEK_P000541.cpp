#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isPossible(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) return true;
        }
    }
    return false;
}

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int fresh = 0, minutes = -1;

    queue<pair<int, int>> q;
    vector<vector<int>> dist(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) fresh++;
            if (grid[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int count = 0;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || dist[nx][ny] != -1 || grid[nx][ny] != 2) continue;

                fresh--;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
            count++;
        }
        if (fresh > 0) minutes = count;
    }

    if (fresh > 0) return -1;
    else return minutes;
}