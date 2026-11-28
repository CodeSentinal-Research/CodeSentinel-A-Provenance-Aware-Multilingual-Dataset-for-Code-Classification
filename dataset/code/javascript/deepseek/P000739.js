function countPaths(N, M, grid) {
    const dp = new Array(N + 1).fill(0).map(() => new Array(M + 1).fill(0));

    dp[0][1] = 1;

    for(let i = 1; i <= N; i++) {
        for(let j = 1; j <= M; j++) {
            if(grid[i - 1][j - 1] === 1) continue; // Skip blocked cell
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }

    return dp[N][M];
}
This function uses a dynamic programming approach to solve the problem. The dp table stores the number of paths from the top-left cell to the current cell. The number of paths is the sum of the paths to the cell to its left and the cell above it, and the final result is the bottom right cell's number of paths.