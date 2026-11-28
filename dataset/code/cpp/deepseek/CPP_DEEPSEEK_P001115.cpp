Here is the C++ code:

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define inf 999999
#define N 1000

int shortest_path(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, inf));
    queue<pair<int, int>> q;
    int dr[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int dc[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

    dist[0][0] = 0;
    q.push({0, 0});

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return dist[n - 1][n - 1] == inf ? -1 : dist[n - 1][n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << shortest_path(grid);

    return 0;
}

This code uses the BFS (Breadth-First Search) algorithm to find the shortest path in the binary matrix. The BFS algorithm visits the nodes at the current level before moving to nodes at the next level. In this case, we start from the top-left cell and try to reach the bottom-right cell.

In each step, we try to move in all eight directions (up, down, left, right and eight possible diagonals). If a cell is valid (i.e., it's not out of the grid and contains 0), we update the distance to this cell if the current distance plus one is less. If we found the bottom-right cell, we return the distance to this cell, otherwise, return -1 to indicate that there is no path.