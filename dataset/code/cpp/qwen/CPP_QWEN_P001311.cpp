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

void solveNQueens(vector<string>& board, int row, int n, vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n, result);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result;
    solveNQueens(board, 0, n, result);
    
    cout << result.size() << endl;
    for (const auto& sol : result) {
        for (const string& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
