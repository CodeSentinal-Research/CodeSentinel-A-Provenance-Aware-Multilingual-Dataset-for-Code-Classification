#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<string> paths;

void floodFill(int x, int y, string path) {
    if (x == N - 1 && y == M - 1) {
        paths.push_back(path);
        return;
    }
    visited[x][y] = true;
    if (x > 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
        floodFill(x - 1, y, path + 'U');
    }
    if (y > 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
        floodFill(x, y - 1, path + 'L');
    }
    if (x < N - 1 && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
        floodFill(x + 1, y, path + 'D');
    }
    if (y < M - 1 && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
        floodFill(x, y + 1, path + 'R');
    }
    visited[x][y] = false;
}

int main() {
    cin >> N >> M;
    grid = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    floodFill(0, 0, "");
    sort(paths.begin(), paths.end());
    for (const string& path : paths) {
        cout << path << endl;
    }
    return 0;
}