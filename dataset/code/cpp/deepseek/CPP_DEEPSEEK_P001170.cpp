Here is the C++ code for your problem:

#include <iostream>
#include <vector>

using namespace std;

int maxCherries(vector<vector<int>> grid, int n) {
    if (n == 1) {
        return grid[0][0];
    }

    int right = maxCherries(grid, n - 1);
    int down = maxCherries(grid, n - 1);

    return max(right, down) + grid[n - 1][n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << maxCherries(grid, n);

    return 0;
}

This code uses recursion to solve the problem. It computes the maximum number of cherries we can get by moving right or down, and then returns the maximum of these two possible maximums plus the cherry at the bottom right corner.

The main function first reads the size of the grid, then reads the grid itself. It then calls the `maxCherries` function with the grid and the size as arguments. The result is printed to the console.