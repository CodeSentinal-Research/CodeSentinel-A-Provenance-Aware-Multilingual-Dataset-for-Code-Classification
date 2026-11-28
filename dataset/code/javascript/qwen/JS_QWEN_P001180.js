const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let days = [];
        for(let i=1; i<=n; i++) days.push(lines[i].split(/\s+/).map(Number));
        let dp = Array.from({length:n}, ()=>new Array(3).fill(0));
        dp[0] = days[0];
        for(let i=1; i<n; i++) {
            dp[i][0] = days[i][0] + Math.max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = days[i][1] + Math.max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = days[i][2] + Math.max(dp[i-1][0], dp[i-1][1]);
        }
        console.log(Math.max(...dp[n-1]));
        rl.close();
    }
});
