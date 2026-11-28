Here is the C++ code to solve the Knight's Tour problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

bool is_valid(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool is_safe(int x, int y, int N, vector<vector<bool>> &visited) {
    return (is_valid(x, y, N) && !visited[x][y]);
}

bool BFS(int start_x, int start_y, int end_x, int end_y, int N, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if(p.first == end_x && p.second == end_y) {
            return true;
        }

        for(int i = 0; i < 8; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];

            if(is_safe(x, y, N, visited)) {
                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    int start_x, start_y;
    cin >> start_x >> start_y;
    start_x--, start_y--;

    vector<vector<bool>> visited(N, vector<bool>(N, false));

    if(!BFS(start_x, start_y, start_x, start_y, N, visited)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

This program uses a Breadth-First Search (BFS) algorithm to solve the Knight's Tour problem. The main idea of BFS is to visit the closest unvisited neighbor first.

In the main function, we first read the number of squares N and the starting coordinates (x, y). Then we initialize a visited array with all elements set to false.

In the BFS function, we start with the starting point and mark it as visited. We then enter a while loop that continues until there are no unvisited neighbors left. For each unvisited neighbor, we add it to the queue and mark it as visited.

If we reach the destination, we return true, indicating that a valid tour has been found. If we reach the end of the queue without finding a valid tour, we return false, indicating that no valid tour exists.

Finally, we print the visited array, which represents the solution to the problem.