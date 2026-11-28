const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let matrix = [];
        for(let i=1; i<=n; i++) matrix.push(lines[i].split(/\s+/).map(Number));
        let dp = matrix[n-1].slice();
        for(let i=n-2; i>=0; i--) {
            let newDp = new Array(n).fill(0);
            for(let j=0; j<n; j++) {
                let minPrev = dp[j];
                if(j>0) minPrev = Math.min(minPrev, dp[j-1]);
                if(j<n-1) minPrev = Math.min(minPrev, dp[j+1]);
                newDp[j] = matrix[i][j] + minPrev;
            }
            dp = newDp;
        }
        console.log(Math.min(...dp));
        rl.close();
    }
});
