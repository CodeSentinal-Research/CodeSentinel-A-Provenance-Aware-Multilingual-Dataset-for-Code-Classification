Here is the C++ code for your problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minSteps(vector<vector<int>> forest, pair<int, int> start) {
    int m = forest.size();
    int n = forest[0].size();

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, start});
    visited[start.first][start.second] = true;

    while (!pq.empty()) {
        int steps = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (steps == m * n) return steps;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.push({steps + 1, {nx, ny}});
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> forest = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}};
    pair<int, int> start = {0, 0};

    cout << minSteps(forest, start) << endl;

    return 0;
}

This code uses Breadth-First Search (BFS) algorithm to find the minimum number of steps to cut all trees. It starts from the starting position and explores all neighboring positions. If a position is an obstacle or has been visited before, it is skipped. If it is a tree and not visited before, it is pushed into the priority queue with the number of steps. The BFS terminates when all trees have been cut or when there is no tree left to cut. If a tree cannot be cut, the function returns -1.