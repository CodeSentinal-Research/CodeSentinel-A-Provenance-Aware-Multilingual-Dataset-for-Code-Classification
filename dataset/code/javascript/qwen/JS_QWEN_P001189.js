const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const prices = lines[1].split(/\s+/).map(Number);
        let dp = Array.from({length:k+1}, ()=>new Array(n).fill(0));
        for(let i=1; i<=k; i++) {
            let maxPrev = -prices[0];
            for(let j=1; j<n; j++) {
                dp[i][j] = Math.max(dp[i][j-1], prices[j]+maxPrev);
                maxPrev = Math.max(maxPrev, dp[i-1][j]-prices[j]);
            }
        }
        console.log(dp[k][n-1]);
        rl.close();
    }
});
