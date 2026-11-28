const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        let sum = nums.reduce((a,b)=>a+b, 0);
        if((sum+target)%2 !== 0 || Math.abs(target) > sum) { console.log(0); rl.close(); return; }
        let s = (sum+target)/2;
        let dp = new Array(s+1).fill(0);
        dp[0] = 1;
        for(let num of nums) {
            for(let j=s; j>=num; j--) {
                dp[j] += dp[j-num];
            }
        }
        console.log(dp[s]);
        rl.close();
    }
});
