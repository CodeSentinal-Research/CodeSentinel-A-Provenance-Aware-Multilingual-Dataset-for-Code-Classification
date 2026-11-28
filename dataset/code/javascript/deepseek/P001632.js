const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter N M K: ', (N) => {
    let matrix = [];
    rl.setPrompt('Enter matrix values: ');
    for (let i = 0; i < N; i++) {
        matrix[i] = rl.question('').split(' ').map(Number);
    }

    rl.question('Enter K: ', (K) => {
        console.log(largestSquareWithSumNotExceedingK(matrix, K));
        rl.close();
    });
});

function largestSquareWithSumNotExceedingK(matrix, K) {
    let N = matrix.length;
    let M = matrix[0].length;

    let dp = Array.from(new Array(N + 1), () => new Array(M + 1).fill(0));

    for (let i = 1; i <= N; i++) {
        for (let j = 1; j <= M; j++) {
            dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + matrix[i - 1][j - 1];
            if (dp[i][j] <= K) {
                let size = Math.min(i, j);
                while (dp[i - size][j] > K || dp[i][j - size] > K || dp[i - size][j - size] > K) {
                    size--;
                }
                return size;
            }
        }
    }

    return 0;
}
This code uses a dynamic programming approach to solve the problem. It creates a 2D array `dp` and initializes the first row and column to 0. Then it fills up the rest of the `dp` array. The final result is the minimum of the three possibilities: the current cell, the cell above it, and the cell above and left of it. If the sum of the current cell's value and the minimum sum is greater than `K`, it decreases the size of the largest square until the sum is not greater than `K`.