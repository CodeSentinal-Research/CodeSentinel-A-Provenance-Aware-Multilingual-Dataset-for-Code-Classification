#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
        if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false;
    }
    return true;
}

void countNQueens(vector<string>& board, int row, int n, int& count) {
    if (row == n) {
        count++;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            countNQueens(board, row + 1, n, count);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    int count = 0;
    countNQueens(board, 0, n, count);
    cout << count << endl;
    return 0;
}
