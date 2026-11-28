const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [e, f] = input.split(/\s+/).map(Number);
    let dp = Array.from({length: e+1}, ()=>Array(f+1).fill(Infinity));
    
    for (let i = 1; i <= e; i++) {
        for (let j = 1; j <= f; j++) {
            if (i === 1) {
                dp[i][j] = j;
            } else if (j === 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = Infinity;
                for (let k = 1; k <= j; k++) {
                    dp[i][j] = Math.min(dp[i][j], 1 + Math.max(dp[i-1][k-1], dp[i][j-k]));
                }
            }
        }
    }
    console.log(dp[e][f]);
    rl.close();
});
