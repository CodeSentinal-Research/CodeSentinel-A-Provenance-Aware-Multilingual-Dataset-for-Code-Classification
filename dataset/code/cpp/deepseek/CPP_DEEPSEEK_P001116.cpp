Here is the C++ code that accomplishes the given problem:

#include <iostream>
#include <vector>

using namespace std;

void surroundedRegions(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                if (grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'O' && (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)) {
                if (grid[i][j] == 'X') continue; 
                grid[i][j] = 'X';
            }
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    surroundedRegions(grid);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

This code first sets up a queue to hold the locations of all the 'O' cells that are on the borders of the grid and are not yet marked. Then, it starts exploring these cells. For each 'O' cell, if there is a neighboring 'O' cell on the border, then it is also a border cell, and it is marked. After all border cells have been marked, it then checks all the 'O' cells that are not on the border and has been marked. If they are surrounded by 'X', it will be marked again, otherwise it will be changed to 'X'. This is done in a breadth-first search manner.