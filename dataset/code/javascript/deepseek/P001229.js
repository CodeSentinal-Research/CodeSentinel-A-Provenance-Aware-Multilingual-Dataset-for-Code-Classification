Sure, here is the JavaScript code that calculates the probability of the knight remaining on the board after moving exactly K times.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter N, K, R, C: ', (n) => {
    let [N, K, R, C] = n.split(' ').map(x => parseInt(x));
    if (N < 1 || N > 50 || K < 0 || K > 100 || R < 0 || R > N || C < 0 || C > N || N * N != K) {
        rl.setPrompt(`Invalid input! Please enter N, K, R, C again (1 ≤ N ≤ 50, 0 ≤ K ≤ 100, 1 ≤ R ≤ N, 1 ≤ C ≤ N).`);
        rl.prompt();
        return;
    }

    let dp = new Array(N + 1).fill(0).map(() => new Array(N + 1).fill(0));
    dp[R][C] = 1;
    for (let i = 0; i < K; i++) {
        dp = dp.map((row, rowIdx) => row.map((col, colIdx) => {
            let sum = 0;
            if (rowIdx > 0) sum += dp[rowIdx - 1][colIdx];
            if (colIdx > 0) sum += dp[rowIdx][colIdx - 1];
            return sum;
        }));
    }

    let ans = dp.flat().reduce((a, b) => a + b, 0);
    console.log((ans / Math.pow(N, 2)).toFixed(10));
    rl.close();
});

In the above code, we use a dynamic programming approach to solve the problem. The state of the game board is represented by a 2D array `dp`. `dp[i][j]` represents the probability that the knight is on cell `(i, j)` after moving for `K` times. The initial state is `(R, C)`, and the probability that the knight is on this cell is 1. Then we use a loop to iterate `K` times, and for each move, we update the probability by summing up the probabilities of the adjacent cells. At the end, we calculate the total probability by summing up all the probabilities in the 2D array.