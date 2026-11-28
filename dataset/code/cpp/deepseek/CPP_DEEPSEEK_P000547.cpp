#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int maxMinutes(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    int fire[m][n];
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            fire[i][j] = grid[i][j];
            if(fire[i][j] == 1) q.push({i, j});
        }
    }

    int dist = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || fire[nx][ny] == 1 || grid[nx][ny] == 2) continue;

                if(fire[nx][ny] == 0) {
                    fire[nx][ny] = 1;
                    q.push({nx, ny});
                }
                else if(grid[nx][ny] == 0) {
                    grid[nx][ny] = fire[x][y];
                    q.push({nx, ny});
                }
            }
        }
        dist++;
    }

    if(fire[m-1][n-1] == 1) return -1;
    else return dist;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << maxMinutes(grid);

    return 0;
}

This code uses the BFS algorithm to find the shortest path from the top-left cell to the bottom-right cell. The BFS algorithm is used because it can find the shortest path in the grid by traversing all possible paths in the graph (in this case, the grid).

The algorithm starts by initializing a 2D array `fire` to store the status of each cell, and a queue `q` to store the cells to be processed. It then fills the `fire` array and the `q` queue with the initial grid.

The main part of the code is the while loop which runs for the number of minutes (initially 0). For each minute, it processes all the cells in the queue. For each cell, it checks all its adjacent cells (top, right, bottom, left) and if the adjacent cell is not a wall and not fire, it adds it to the queue to be processed in the next minute. If the adjacent cell is a wall or fire, it marks it as the current cell's status.

After each minute, it increments the `dist` variable by 1.

At the end, it checks if there is any fire left in the grid. If there is, it returns -1, otherwise it returns the maximum number of minutes.