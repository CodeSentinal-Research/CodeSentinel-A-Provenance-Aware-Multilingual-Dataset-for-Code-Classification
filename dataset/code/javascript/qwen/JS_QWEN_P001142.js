const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let sum = nums.reduce((a,b)=>a+b, 0);
        if(sum % 2 !== 0) { console.log("NO"); rl.close(); return; }
        let target = sum / 2;
        let dp = new Array(target+1).fill(false);
        dp[0] = true;
        for(let num of nums) {
            for(let j=target; j>=num; j--) {
                if(dp[j-num]) dp[j] = true;
            }
        }
        console.log(dp[target] ? "YES" : "NO");
        rl.close();
    }
});
