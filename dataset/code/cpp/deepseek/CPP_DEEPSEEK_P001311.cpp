Here is the complete C++ code for the problem:

#include <iostream>
#include <vector>
using namespace std;

int solveNQueens(int n) {
    if (n < 1 || n > 14) {
        return 0;
    }

    vector<int> board(n, -1);
    int count = 0;
    placeQueens(board, 0, count);
    return count;
}

void placeQueens(vector<int>& board, int row, int& count) {
    int n = board.size();
    if (row == n) {
        count++;
        printBoard(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            placeQueens(board, row + 1, count);
            board[row] = -1;
        }
    }
}

bool isSafe(const vector<int>& board, int row1, int col1, int n) {
    int row2 = 0;
    while (row2 < row1) {
        if (board[row2] == col1 || board[row2] == -1) {
            return false;
        }
        row2++;
    }

    return true;
}

void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << "_ ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    int count = solveNQueens(n);
    cout << "Total number of solutions: " << count << "\n";

    return 0;
}

This code uses the backtracking technique to find all the solutions. The `solveNQueens` function starts by creating a board of size `n` filled with -1 (indicating an empty slot). It then calls the `placeQueens` function to place queens on the board, starting from the first row.

The `placeQueens` function is a recursive function that tries to place a queen in each column of the current row. If a queen can be placed in a column without being attacked by other queens in the same row or the same column, it is placed there. If it is not possible to place a queen in a column, it moves to the next row.

The `isSafe` function is used to check if a queen can be placed in a certain column in a certain row without being attacked by other queens in the same row or the same column.

The `printBoard` function is used to print the board, with the queens marked with 'Q' and the rest marked with '_'.