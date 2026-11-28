Here's the JavaScript code for the problem:

function solve() {
    const rows = readLine();
    const grid = [];

    // Read grid
    for (let i = 0; i < rows; i++) {
        const line = readLine();
        const row = line.split(' ').map(Number);
        grid.push(row);
    }

    // Solve problem
    let sum = 0;
    let start = null;
    let end = null;
    let empty = 0;
    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];

    function dfs(x, y, empty, sum) {
        if (x < 0 || x >= rows || y < 0 || y >= rows || grid[x][y] < 0) {
            return 0;
        }

        if (grid[x][y] === 2) {
            if (empty === 0) {
                return 0;
            }

            return sum;
        }

        if (grid[x][y] === 1) {
            return sum;
        }

        grid[x][y] = -2;
        empty--;
        let paths = directions.reduce((total, d) => total + dfs(x + d[0], y + d[1], empty, sum), 0);
        grid[x][y] = 0;
        empty++;

        return paths;
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < rows; j++) {
            if (grid[i][j] === 1) {
                start = [i, j];
            }

            if (grid[i][j] === 2) {
                end = [i, j];
            }

            if (grid[i][j] !== -1) {
                sum += dfs(i, j, 3, 0);
            }
        }
    }

    console.log(sum);
}

function readLine() {
    return process.stdin.readLine();
}

This code reads a grid of size R x R, and finds the start and end points, then uses depth-first search to find the number of paths from the start to the end. It only counts paths that visit every non-obstacle square exactly once.