#include <iostream>
#include <vector>

using namespace std;

bool is_valid(vector<vector<char>> &board, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num)
            return false;
        if (board[row][i] == num)
            return false;
    }

    int start_row = row - row % 3;
    int start_col = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + start_row][j + start_col] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(board, i, j, num)) {
                        board[i][j] = num + '0';
                        if (solve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    if (solve(board)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist";
    }

    return 0;
}
This code solves the Sudoku puzzle by trying to fill the empty cells with numbers from 1 to 9 in a backtracking manner. It uses a helper function `is_valid` to check whether a given number can be placed at a given cell without violating the Sudoku rules. If it can, it recursively calls the function again for the next cell until it finds a valid number or it exhausts all the possible numbers. If no valid number is found, it backtracks and tries another number. If it doesn't find another valid number for a cell, it returns false, indicating that no solution exists. If it finds a valid number for all cells, it returns true.