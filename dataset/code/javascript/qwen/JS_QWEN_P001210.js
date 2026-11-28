const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const coins = lines[1].split(/\s+/).map(Number);
        
        let dp = Array.from({length: n}, ()=>new Array(n).fill(0));
        for(let i=0; i<n; i++) dp[i][i] = coins[i];
        
        for(let len=2; len<=n; len++) {
            for(let i=0; i<=n-len; i++) {
                let j = i+len-1;
                let pickLeft = coins[i] + Math.min(dp[i+2][j]||0, dp[i+1][j-1]||0);
                let pickRight = coins[j] + Math.min(dp[i][j-2]||0, dp[i+1][j-1]||0);
                dp[i][j] = Math.max(pickLeft, pickRight);
            }
        }
        console.log(dp[0][n-1]);
        rl.close();
    }
});
