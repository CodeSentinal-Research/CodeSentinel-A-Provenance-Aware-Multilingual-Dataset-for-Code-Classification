Here is a simple C++ solution that uses Breadth-First Search (BFS) to solve the problem. BFS is an algorithm for traversing or searching tree or graph data structures.

#include <iostream>
#include <queue>

using namespace std;

bool isValidMove(int x, int y, int ti, int tj) {
    if (x < 0 || y < 0 || x >= 300 || y >= 300)
        return false;
    if (x == ti && y == tj)
        return true;
    return false;
}

int minKnightMoves(int x, int y) {
    int moves = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            auto cell = q.front();
            q.pop();
            if (isValidMove(cell.first, cell.second, x, y))
                return moves;
            for (int j = 0; j < 8; j++) {
                int nx = cell.first + (j % 2 == 0 ? 1 : -1), ny = cell.second + (j < 4 ? 2 : -2);
                q.push({nx, ny});
            }
        }
        moves++;
    }
    return -1; 
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << minKnightMoves(x, y);
    return 0;
}
This code will output the minimum number of moves the knight needs to reach the target cell (x, y). The `isValidMove` function checks if a cell is within the board and if it is the target cell. The `minKnightMoves` function uses a BFS approach to find the minimum number of moves. In the main function, it reads the target cell coordinates and outputs the result of `minKnightMoves`.