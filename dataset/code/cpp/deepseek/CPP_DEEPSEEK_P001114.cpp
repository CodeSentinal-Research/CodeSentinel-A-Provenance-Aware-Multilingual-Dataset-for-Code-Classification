#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int rotOranges(int R, int C, vector<vector<int>> grid) {
    queue<pair<int, pair<int, int>>> q;
    int fresh = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 1) fresh++;
            else if (grid[i][j] == 2) q.push({i, {j, 0}});
        }
    }

    if (fresh == 0) return 0;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second.first;
        int time = q.front().second.second;
        q.pop();

        if (i > 0 && grid[i - 1][j] == 1) {
            fresh--;
            grid[i - 1][j] = 2;
            q.push({i - 1, {j, time + 1}});
        }
        if (j > 0 && grid[i][j - 1] == 1) {
            fresh--;
            grid[i][j - 1] = 2;
            q.push({i, {j - 1, time + 1}});
        }
        if (i < R - 1 && grid[i + 1][j] == 1) {
            fresh--;
            grid[i + 1][j] = 2;
            q.push({i + 1, {j, time + 1}});
        }
        if (j < C - 1 && grid[i][j + 1] == 1) {
            fresh--;
            grid[i][j + 1] = 2;
            q.push({i, {j + 1, time + 1}});
        }
    }

    if (fresh > 0) return -1;

    return time;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    cout << rotOranges(R, C, grid);
    return 0;
}