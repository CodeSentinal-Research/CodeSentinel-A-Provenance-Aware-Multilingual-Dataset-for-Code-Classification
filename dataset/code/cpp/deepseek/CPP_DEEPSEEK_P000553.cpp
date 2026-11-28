Here is the C++ code for the problem:

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

int min_moves(std::vector<std::vector<int>> board, int n) {
    std::vector<bool> visited(n+1, false);
    std::vector<int> dist(n+1, -1);
    dist[1] = 0;
    visited[1] = true;

    std::queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = cur + i;

            if (next <= n && !visited[next]) {
                visited[next] = true;
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    return dist[n];
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> board(n+1, std::vector<int>(n+1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> board[i][j];
        }
    }

    int moves = min_moves(board, n);

    if (moves == -1) {
        std::cout << "Impossible";
    } else {
        std::cout << moves;
    }

    return 0;
}

This code reads the board input from the standard input, then calls the `min_moves` function with the board and the board size as arguments. The `min_moves` function uses breadth-first search (BFS) to find the minimum number of moves from square 1 to the destination. If it is impossible to reach the destination, it returns -1. Otherwise, it returns the minimum number of moves. The main function prints the result of `min_moves` with a corresponding message.