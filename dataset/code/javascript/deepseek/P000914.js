Here is the JavaScript code that solves the problem:

function uniquePaths(m, n) {
    // Create a 2D array to store the number of unique paths
    let paths = new Array(m);
    for (let i = 0; i < m; i++) {
        paths[i] = new Array(n).fill(-1);
    }

    // Define a recursive function to calculate the number of unique paths
    function calculatePaths(x, y) {
        // If the destination is reached, return 1
        if (x == m - 1 && y == n - 1) {
            return 1;
        }

        // If the destination is out of bounds, return 0
        if (x >= m || y >= n) {
            return 0;
        }

        // If the number of unique paths is already calculated, return the stored value
        if (paths[x][y] != -1) {
            return paths[x][y];
        }

        // Calculate the number of unique paths and store it in the path array
        paths[x][y] = calculatePaths(x + 1, y) + calculatePaths(x, y + 1);
        return paths[x][y];
    }

    // Calculate and return the number of unique paths
    return calculatePaths(0, 0);
}

// Test the function
console.log(uniquePaths(3, 3)); // 6
This code works by using dynamic programming to store the number of unique paths to each cell. The function `calculatePaths` recursively calculates the number of unique paths from the top-left corner to the bottom-right corner. If the destination is reached, it returns 1, and if it is out of bounds, it returns 0. If the number of unique paths to a cell has already been calculated, it returns the stored value. Otherwise, it calculates the number of unique paths to the cell and stores it in the path array, then returns the number of unique paths to the cell. The function `uniquePaths` calculates and returns the total number of unique paths from the top-left corner to the bottom-right corner.