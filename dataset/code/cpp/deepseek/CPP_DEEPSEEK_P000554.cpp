#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int shortestDistance(vector<vector<char>> &maze, pair<int, int> &entrance) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push(entrance);
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while(!q.empty()) {
        auto cell = q.front();
        q.pop();
        for(auto &dir : directions) {
            int x = cell.first + dir.first;
            int y = cell.second + dir.second;
            if(x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == '+' || dist[x][y] != -1)
                continue;
            dist[x][y] = dist[cell.first][cell.second] + 1;
            q.push({x, y});
        }
    }

    int minDistance = INT_MAX;
    for(auto &row : dist) {
        for(auto &cell : row) {
            if(cell != -1 && cell < minDistance) {
                minDistance = cell;
            }
        }
    }
    return minDistance == INT_MAX ? -1 : minDistance;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> maze(m, vector<char>(n));
    pair<int, int> entrance;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'E') {
                entrance = {i, j};
            }
        }
    }
    int steps = shortestDistance(maze, entrance);
    cout << steps;
    return 0;
}