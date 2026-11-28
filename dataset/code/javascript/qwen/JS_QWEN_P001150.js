const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let dp = Array.from({length:n}, ()=>new Array(n).fill(0));
    for(let i=n-1; i>=0; i--) {
        dp[i][i] = 1;
        for(let j=i+1; j<n; j++) {
            if(s[i]===s[j]) dp[i][j] = dp[i+1][j-1]+2;
            else dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
        }
    }
    console.log(dp[0][n-1]);
    rl.close();
});
