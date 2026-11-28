function maximumPath(N, Matrix) {
    // dp table storing optimal subproblem solutions
    const dp = Matrix.map(row => [...row]);

    for (let i = 1; i < N; i++) {
        for (let j = 0; j < N; j++) {
            // Update dynamic programming state transition
            const up = dp[i - 1][j];
            // Update dynamic programming state transition
            const upLeft = j > 0 ? dp[i - 1][j - 1] : 0;
            // Update dynamic programming state transition
            const upRight = j < N - 1 ? dp[i - 1][j + 1] : 0;
            // Update dynamic programming state transition
            dp[i][j] += Math.max(up, upLeft, upRight);
        }
    }

    return Math.max(...dp[N - 1]);
}

module.exports = { maximumPath };