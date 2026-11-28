const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let dp = new Array(n).fill(1);
        let count = new Array(n).fill(1);
        let maxLen = 1;
        
        for(let i=1; i<n; i++) {
            for(let j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    } else if(dp[j]+1 === dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = Math.max(maxLen, dp[i]);
        }
        
        let res = 0;
        for(let i=0; i<n; i++) if(dp[i]===maxLen) res+=count[i];
        console.log(res);
        rl.close();
    }
});
