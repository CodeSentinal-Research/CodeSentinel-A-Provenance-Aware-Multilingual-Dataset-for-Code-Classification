Here is the C++ code for the given problem:

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minVisitedCells(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({grid[0][0], {0, 0}});
    visited[0][0] = true;

    while (!pq.empty()) {
        auto cell = pq.top(); pq.pop();
        int steps = cell.first;
        int x = cell.second.first;
        int y = cell.second.second;

        if (x == m - 1 && y == n - 1) {
            return steps;
        }

        for (int dx = -grid[0][0]; dx <= grid[0][0]; ++dx) {
            int nx = x + dx;
            if (nx >= 0 && nx < m && !visited[nx][y]) {
                visited[nx][y] = true;
                pq.push({steps + 1 + abs(dx), {nx, y}});
            }
        }

        for (int dy = -grid[0][0]; dy <= grid[0][0]; ++dy) {
            int ny = y + dy;
            if (ny >= 0 && ny < n && !visited[x][ny]) {
                visited[x][ny] = true;
                pq.push({steps + 1 + abs(dy), {x, ny}});
            }
        }
    }

    return -1;
}

int main() {

    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    cout << minVisitedCells(grid);

    return 0;
}

This code uses a breadth-first search (BFS) algorithm with a priority queue to find the shortest path from the top-left cell to the bottom-right cell. The visited array is used to keep track of the cells that have been visited. The priority queue is used to efficiently select the cell with the minimum steps to reach the destination. If the destination cannot be reached, the function returns -1.