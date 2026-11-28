const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let count = {};
        let maxVal = 0;
        for(let num of nums) {
            count[num] = (count[num]||0)+num;
            maxVal = Math.max(maxVal, num);
        }
        let dp = new Array(maxVal+1).fill(0);
        dp[1] = count[1]||0;
        for(let i=2; i<=maxVal; i++) {
            dp[i] = Math.max(dp[i-1], (count[i]||0)+dp[i-2]);
        }
        console.log(dp[maxVal]);
        rl.close();
    }
});
