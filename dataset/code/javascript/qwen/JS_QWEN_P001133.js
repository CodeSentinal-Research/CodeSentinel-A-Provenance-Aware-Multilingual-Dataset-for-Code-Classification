const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const cost = lines[1].split(/\s+/).map(Number);
        let dp = new Array(n+1).fill(0);
        dp[0] = 0;
        dp[1] = cost[0];
        for(let i=2; i<=n; i++) {
            dp[i] = Math.min(dp[i-1], dp[i-2]) + (cost[i-1] || 0);
        }
        console.log(Math.min(dp[n], dp[n-1]));
        rl.close();
    }
});
