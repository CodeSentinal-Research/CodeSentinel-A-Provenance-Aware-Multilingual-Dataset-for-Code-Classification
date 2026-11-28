const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const heights = lines[1].split(/\s+/).map(Number);
        let dp = new Array(n).fill(0);
        for(let i=1; i<n; i++) {
            dp[i] = dp[i-1] + Math.abs(heights[i]-heights[i-1]);
            if(i>1) dp[i] = Math.min(dp[i], dp[i-2] + Math.abs(heights[i]-heights[i-2]));
        }
        console.log(dp[n-1]);
        rl.close();
    }
});
