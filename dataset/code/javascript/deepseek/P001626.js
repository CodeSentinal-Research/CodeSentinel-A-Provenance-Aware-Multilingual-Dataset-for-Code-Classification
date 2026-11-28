let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter N, M, and Threshold: ', (N) => {
    let matrix = [];
    rl.setPrompt('Enter matrix values: ');
    for(let i = 0; i < N; i++) {
        matrix[i] = rl.question('').split(' ').map(Number);
    }

    rl.question('Enter Threshold: ', (Threshold) => {
        console.log(maxSideLength(matrix, Threshold));
        rl.close();
    });
});

function maxSideLength(matrix, threshold) {
    let N = matrix.length;
    let M = matrix[0].length;

    let dp = Array.from(Array(N + 1), () => Array(M + 1).fill(0));
    for(let i = 1; i <= N; i++) {
        for(let j = 1; j <= M; j++) {
            dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + matrix[i - 1][j - 1]);
            if(dp[i][j] >= threshold) dp[i][j] = Math.sqrt(dp[i][j]);
        }
    }

    return Math.floor(dp[N][M]);
}