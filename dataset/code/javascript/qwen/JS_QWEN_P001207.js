const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const piles = lines[1].split(/\s+/).map(Number);
        
        let sum = piles.reduce((a,b)=>a+b, 0);
        let dp = Array.from({length: n}, ()=>new Array(n).fill(0));
        
        for(let len=1; len<=n; len++) {
            for(let i=0; i<=n-len; i++) {
                let j = i+len-1;
                if(i===j) dp[i][j] = piles[i];
                else {
                    dp[i][j] = Math.max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
                }
            }
        }
        console.log(dp[0][n-1] > 0 ? "YES" : "NO");
        rl.close();
    }
});
