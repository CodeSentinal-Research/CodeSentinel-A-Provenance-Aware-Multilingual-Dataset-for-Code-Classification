const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, diff] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let dp = {};
        let maxLen = 0;
        for (let x of nums) {
            dp[x] = (dp[x - diff] || 0) + 1;
            maxLen = Math.max(maxLen, dp[x]);
        }
        console.log(maxLen);
        rl.close();
    }
});
