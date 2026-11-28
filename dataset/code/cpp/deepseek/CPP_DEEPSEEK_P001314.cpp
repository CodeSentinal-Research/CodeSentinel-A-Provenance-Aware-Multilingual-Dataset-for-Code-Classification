#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int val = board[i][j];
            if (val != 0) {
                if (val < 1 || val > 9 || (val % 1 == 0)) {
                    return false;
                }
                if (val != board[i][j] || val != board[i][val % 9] || val != board[val % 9][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board;
    for (int i = 0; i < 9; i++) {
        vector<int> row(9);
        for (int j = 0; j < 9; j++) {
            cin >> row[j];
        }
        board.push_back(row);
    }

    if (isValidSudoku(board)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}