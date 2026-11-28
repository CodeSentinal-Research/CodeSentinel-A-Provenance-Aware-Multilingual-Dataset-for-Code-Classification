const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const heights = lines[1].split(/\s+/).map(Number);
        let dp = new Array(n).fill(Infinity);
        dp[0] = 0;
        for(let i=1; i<n; i++) {
            for(let j=1; j<=k; j++) {
                if(i-j >= 0) dp[i] = Math.min(dp[i], dp[i-j] + Math.abs(heights[i]-heights[i-j]));
            }
        }
        console.log(dp[n-1]);
        rl.close();
    }
});
