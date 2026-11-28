function uniquePaths(R, C) {
    let dp = new Array(R);
    for (let i = 0; i < R; i++) {
        dp[i] = new Array(C);
        dp[i][0] = 1;
    }
    for (let j = 0; j < C; j++) {
        dp[0][j] = 1;
    }
    for (let i = 1; i < R; i++) {
        for (let j = 1; j < C; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[R - 1][C - 1];
}

function solve() {
    let input = process.stdin;
    input.readline((line) => {
        let [R, C] = line.split(' ').map(Number);
        console.log(uniquePaths(R, C));
        solve();
    });
}

solve();

This solution uses a dynamic programming approach to solve the problem. The `dp[i][j]` represents the number of unique paths from the cell at (0, 0) to (i, j). It uses the fact that the number of unique paths to any cell is the sum of the paths to the cell above and to the left of the cell.