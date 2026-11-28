Here is the complete C++ code for the problem:

#include <iostream>
using namespace std;

bool is_safe(int board[12][12], int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j])
            return false;
    }

    for (int i=row, j=col; row>i && col>j; i--, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

void solve_n_queens(int board[12][12], int col, int N) {
    if (col >= N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j])
                    cout << "Q " << i << " " << j << endl;
            }
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (is_safe(board, i, col, N)) {
            board[i][col] = true;
            solve_n_queens(board, col + 1, N);
            board[i][col] = false; 
        }
    }
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    int board[12][12] = {0};

    solve_n_queens(board, 0, N);

    return 0;
}

This program uses backtracking to solve the N-Queens problem. It creates a 2D boolean array 'board' to represent the chessboard. The 'is_safe' function checks if a queen can be placed at a given position (i, j) considering the previous queens. If a queen can be placed, it returns true; otherwise, it returns false. In the 'solve_n_queens' function, if all queens can be placed, it prints the positions of the queens. If not, it backtracks and tries the next row.