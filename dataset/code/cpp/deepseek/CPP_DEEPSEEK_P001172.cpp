#include <iostream>
using namespace std;

int uniquePaths(int R, int C) {
    int** grid = new int*[R];
    for(int i = 0; i < R; i++) {
        grid[i] = new int[C];
        for(int j = 0; j < C; j++) {
            grid[i][j] = 1; 
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(i > 0)
                grid[i][j] += grid[i-1][j];
            if(j > 0)
                grid[i][j] += grid[i][j-1];
        }
    }

    int result = grid[R-1][C-1];

    for(int i = 0; i < R; i++)
        delete [] grid[i];
    delete [] grid;

    return result;
}

int main() {
    int R, C;
    cin >> R >> C;
    cout << uniquePaths(R, C);
    return 0;
}
This C++ code creates a 2D grid with dimensions R x C, where each cell is initialized with 1 (signifying a free cell). It then iterates through the grid, updating each cell to the sum of the cells above and to the left of it. The final result is the bottom right cell, which is the number of unique paths.