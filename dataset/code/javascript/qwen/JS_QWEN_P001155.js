const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let arr = [1, ...nums, 1];
        let m = arr.length;
        let dp = Array.from({length:m}, ()=>new Array(m).fill(0));
        for(let len=3; len<=m; len++) {
            for(let i=0; i<=m-len; i++) {
                let j = i+len-1;
                for(let k=i+1; k<j; k++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
                }
            }
        }
        console.log(dp[0][m-1]);
        rl.close();
    }
});
