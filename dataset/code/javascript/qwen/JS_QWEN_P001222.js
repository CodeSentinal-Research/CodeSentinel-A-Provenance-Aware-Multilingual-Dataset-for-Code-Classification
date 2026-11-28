const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let dp = new Array(n+1).fill(0);
    dp[0] = 1;
    for(let i=1; i<=n; i++) {
        dp[i] = dp[i-1]*(4*i-2)/(i+1);
    }
    console.log(dp[n]);
    rl.close();
});
