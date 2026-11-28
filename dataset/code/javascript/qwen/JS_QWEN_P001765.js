const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const n = parseInt(lines[0]);
        const keys = lines[1].split(/\s+/).map(Number);
        const freq = lines[2].split(/\s+/).map(Number);
        
        let dp = Array.from({length: n}, ()=>Array(n).fill(Infinity));
        let sumFreq = Array.from({length: n}, ()=>Array(n).fill(0));
        
        for (let i = 0; i < n; i++) {
            dp[i][i] = freq[i];
            sumFreq[i][i] = freq[i];
        }
        
        for (let len = 2; len <= n; len++) {
            for (let i = 0; i <= n - len; i++) {
                let j = i + len - 1;
                sumFreq[i][j] = sumFreq[i][j-1] + freq[j];
                dp[i][j] = Infinity;
                for (let r = i; r <= j; r++) {
                    let cost = (r > i ? dp[i][r-1] : 0) + (r < j ? dp[r+1][j] : 0) + sumFreq[i][j];
                    dp[i][j] = Math.min(dp[i][j], cost);
                }
            }
        }
        console.log(dp[0][n-1]);
        rl.close();
    }
});
