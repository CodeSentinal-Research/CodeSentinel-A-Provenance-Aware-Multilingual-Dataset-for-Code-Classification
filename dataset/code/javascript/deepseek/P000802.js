Sure, here is a JavaScript solution for the problem:

function maxSideLength(N, M, grid, threshold) {
    let maxLength = 0;
    let dp = new Array(N + 1);
    for(let i = 0; i <= N; i++) {
        dp[i] = new Array(M + 1).fill(0);
    }

    for(let i = 1; i <= N; i++) {
        for(let j = 1; j <= M; j++) {
            dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + grid[i - 1][j - 1];
            if(dp[i][j] <= threshold) {
                maxLength = Math.max(maxLength, dp[i][j]);
            }
        }
    }

    while(maxLength > 0) {
        if(dp[N][M] > threshold) {
            N--;
        } else if(dp[N][M] > threshold) {
            M--;
        } else {
            return N;
        }
        maxLength--;
    }

    return N;
}

This function uses a dynamic programming approach to solve the problem. It creates a 2D matrix dp where dp[i][j] is the maximum sum of elements in a square with side length of dp[i][j] up to the current cell (i, j). The dynamic programming approach is based on the fact that if the sum of elements in the current square (dp[i][j]) is less than or equal to the threshold, the maximum square of length dp[i][j] is the square of the maximum of dp[i-1][j], dp[i][j-1], and dp[i-1][j-1] plus the element at (i, j).

The function then iterates over the 2D matrix dp in a descending order of maximum sum until it finds a square whose sum of elements is less than or equal to the threshold. The function returns the maximum length of this square.