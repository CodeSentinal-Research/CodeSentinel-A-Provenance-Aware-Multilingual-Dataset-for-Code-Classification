const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        let dp = new Array(n+1).fill(0);
        for(let i=1; i<=n; i++) {
            let maxVal = -Infinity, sum = 0;
            for(let j=1; j<=k && i-j>=0; j++) {
                maxVal = Math.max(maxVal, nums[i-j]);
                dp[i] = Math.max(dp[i], dp[i-j] + maxVal*j);
            }
        }
        console.log(dp[n]);
        rl.close();
    }
});
