Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < board.size()) && (y >= 0 && y < board.size()) && (board[x][y] == -1);
}

void solve(int x, int y, int moves, vector<vector<int>>& board, pair<int, int> start, pair<int, int> end) {
    if (moves == board.size() * board.size()) {
        board[x][y] = 0;
        if (x == end.first && y == end.second) {
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board.size(); ++j) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        board[x][y] = -1;
        return;
    }

    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, board)) {
            board[newX][newY] = moves;
            solve(newX, newY, moves + 1, board, start, end);
            board[newX][newY] = -1;
        }
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, -1));
    pair<int, int> start, end;

    cout << "Enter the start position: ";
    cin >> start.first >> start.second;

    cout << "Enter the end position: ";
    cin >> end.first >> end.second;

    board[start.first][start.second] = 0;
    solve(start.first, start.second, 1, board, start, end);

    if (board[end.first][end.second] == -1) {
        cout << "-1" << endl;
    }

    return 0;
}

This code will prompt you to input the size of the board (N), the start and end positions of the knight. It will then print out a board that represents the knight's tour, or -1 if no tour exists.