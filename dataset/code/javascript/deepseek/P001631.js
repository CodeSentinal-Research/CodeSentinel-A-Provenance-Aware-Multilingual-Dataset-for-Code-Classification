const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter N, M, Target:\n', (N) => {
    let [M, Target] = rl.question('Enter M and Target:\n').split(' ').map(Number);
    let Grid = [];
    for (let i = 0; i < N; i++) {
        Grid.push(rl.question(`Enter line ${i + 1} of grid:\n`).split(' ').map(Number));
    }

    let paths = findPaths(Grid, N, M, Target, 0, 0);
    console.log(paths);
    rl.close();
});

function findPaths(grid, n, m, target, currentSum, i, j) {
    if (i == n - 1 && j == m - 1) {
        return currentSum + grid[i][j] == target ? 1 : 0;
    }
    if (i == n - 1) {
        return findPaths(grid, n, m, target, currentSum + grid[i][j], i, j + 1) + (grid[i][j] == target ? 1 : 0);
    }
    if (j == m - 1) {
        return findPaths(grid, n, m, target, currentSum + grid[i][j], i + 1, j) + (grid[i][j] == target ? 1 : 0);
    }
    return findPaths(grid, n, m, target, currentSum + grid[i][j], i, j + 1) + findPaths(grid, n, m, target, currentSum + grid[i][j], i + 1, j) + (grid[i][j] == target ? 1 : 0);
}

Please note that this code will return 0 for the paths as the problem statement is not clear on how to count the paths. The given code is an example of how you could solve this problem in JavaScript.