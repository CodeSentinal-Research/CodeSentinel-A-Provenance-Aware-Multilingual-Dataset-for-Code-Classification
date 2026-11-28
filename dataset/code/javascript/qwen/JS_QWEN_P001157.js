const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const prices = lines[1].split(/\s+/).map(Number);
        let dp = new Array(n+1).fill(0);
        for(let i=1; i<=n; i++) {
            for(let j=1; j<=i; j++) {
                dp[i] = Math.max(dp[i], prices[j-1]+dp[i-j]);
            }
        }
        console.log(dp[n]);
        rl.close();
    }
});
