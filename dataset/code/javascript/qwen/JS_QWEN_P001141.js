const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, s] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        let dp = new Array(s+1).fill(false);
        dp[0] = true;
        for(let num of nums) {
            for(let j=s; j>=num; j--) {
                if(dp[j-num]) dp[j] = true;
            }
        }
        console.log(dp[s] ? "YES" : "NO");
        rl.close();
    }
});
