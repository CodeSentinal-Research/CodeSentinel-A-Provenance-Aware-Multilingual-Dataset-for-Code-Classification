Here is the C++ code:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minMoves(vector<vector<int>> grid, int n) {
    int dx[] = {0, 1};
    int dy[] = {1, 0};

    int startX = 0, startY = 0, targetX = n - 1, targetY = n - 1;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    pq.push({0, {startX, startY}});
    visited[startX][startY] = true;

    while(!pq.empty()) {
        int moves = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(x == targetX && y == targetY) return moves;

        for(int i = 0; i < 2; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !grid[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.push({moves + 1, {nx, ny}});
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << minMoves(grid, n);
    return 0;
}
This code uses a Breadth-First Search (BFS) to find the minimum moves required for the snake to reach the target position. The BFS is implemented by pushing all the starting positions to the priority queue and then expanding the positions that are adjacent to the current position in the queue. The visited array is used to ensure that a position is not visited again after it has been visited in the BFS.