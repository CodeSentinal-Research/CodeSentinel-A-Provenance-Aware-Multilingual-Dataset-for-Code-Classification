Sure, here is the C++ code for the Sudoku Solver problem. This code uses backtracking algorithm to solve the Sudoku.

#include <iostream>
using namespace std;

void printGrid(int grid[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(int grid[9][9], int row, int col, int num) {
    for(int x = 0; x <= 9; x++) {
        if(grid[row][x] == num)
            return false;
    }
    return true;
}

bool isSafeCol(int grid[9][9], int col, int num) {
    for(int x = 0; x <= 9; x++) {
        if(grid[x][col] == num)
            return false;
    }
    return true;
}

bool isSafeBox(int grid[9][9], int row, int col, int num) {
    int r = row - row % 3;
    int c = col - col % 3;

    for(int i = r; i < r + 3; i++) {
        for(int j = c; j < c + 3; j++) {
            if(grid[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(grid[i][j] == 0) {
                for(int num = 1; num <= 9; num++) {
                    if(isSafe(grid, i, j, num) && isSafeCol(grid, j, num) && isSafeBox(grid, i - i % 3, j - j % 3, num)) {
                        grid[i][j] = num;
                        if(solveSudoku(grid)) {
                            return true;
                        } else {
                            grid[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int grid[9][9] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

    if(solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}

This program starts by initializing a 9x9 matrix with 0s for the grid. It then calls a function to solve the Sudoku. The solveSudoku function uses a recursive backtracking algorithm to solve the Sudoku puzzle. If it finds a solution, it prints the grid. If it doesn't find a solution, it prints "No solution exists".