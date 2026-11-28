const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        let dp = new Array(n).fill(1);
        let parent = new Array(n).fill(-1);
        let maxIdx = 0;
        for(let i=1; i<n; i++) {
            for(let j=0; j<i; j++) {
                if(nums[i] % nums[j] === 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > dp[maxIdx]) maxIdx = i;
        }
        let res = [];
        let curr = maxIdx;
        while(curr !== -1) {
            res.push(nums[curr]);
            curr = parent[curr];
        }
        console.log(res.reverse().join(" "));
        rl.close();
    }
});
