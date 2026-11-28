const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const leaves = lines[1].split(/\s+/).map(Number);
        
        let dp = Array.from({length: n}, ()=>new Array(n).fill(Infinity));
        let maxLeaf = Array.from({length: n}, ()=>new Array(n).fill(0));
        
        for(let i=0; i<n; i++) {
            dp[i][i] = 0;
            maxLeaf[i][i] = leaves[i];
        }
        
        for(let len=2; len<=n; len++) {
            for(let i=0; i<=n-len; i++) {
                let j = i+len-1;
                maxLeaf[i][j] = Math.max(maxLeaf[i][j-1], leaves[j]);
                for(let k=i; k<j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k+1][j] + maxLeaf[i][k]*maxLeaf[k+1][j]);
                }
            }
        }
        console.log(dp[0][n-1]);
        rl.close();
    }
});
