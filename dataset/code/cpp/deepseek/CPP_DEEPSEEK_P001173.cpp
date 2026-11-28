Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    int grid[R][C];
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(i > 0 && j > 0) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            } else if(i > 0) {
                grid[i][j] += grid[i-1][j];
            } else if(j > 0) {
                grid[i][j] += grid[i][j-1];
            }
        }
    }

    cout << grid[R-1][C-1] << endl;

    return 0;
}
This program reads the size of the grid from the input and then reads the grid itself. It then calculates the minimum path sum from the top-left corner to the bottom-right corner by either moving right or down. The final result is printed out.