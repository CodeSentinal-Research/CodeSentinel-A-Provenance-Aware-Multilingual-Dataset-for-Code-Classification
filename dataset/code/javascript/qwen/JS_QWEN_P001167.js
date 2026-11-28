const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let costs = [];
        for(let i=1; i<=n; i++) costs.push(lines[i].split(/\s+/).map(Number));
        let dp = [...costs[0]];
        for(let i=1; i<n; i++) {
            let newDp = [0,0,0];
            newDp[0] = costs[i][0] + Math.min(dp[1], dp[2]);
            newDp[1] = costs[i][1] + Math.min(dp[0], dp[2]);
            newDp[2] = costs[i][2] + Math.min(dp[0], dp[1]);
            dp = newDp;
        }
        console.log(Math.min(...dp));
        rl.close();
    }
});
