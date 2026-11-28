let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
    arr = line.split(' ').map(Number);
    processArray();
}).on('close', function() {
    process.exit();
});

function processArray() {
    const N = arr[0];
    const L = arr[1];
    const M = arr[2];

    if (N < 1 || N > 500 || L < 1 || L > N - L || L + M > N || M > L) {
        console.log("Invalid input");
        return;
    }

    const dp = Array(N + 1).fill(0).map(() => Array(N + 1).fill(0));
    const dp2 = Array(N + 1).fill(0).map(() => Array(N + 1).fill(0));

    for (let i = 1; i <= N; i++) {
        dp[i][i] = arr[i - 1];
        for (let j = i - 1; j > 0; j--) {
            dp[i][j] = Math.max(dp[i][j + 1], dp[j][i] + dp[j + 1][i]);
        }
    }

    let max = -Infinity;

    for (let i = 1; i <= N; i++) {
        for (let j = i + 1; j <= N; j++) {
            max = Math.max(max, dp[i][j]);
        }
    }

    console.log(max);
}