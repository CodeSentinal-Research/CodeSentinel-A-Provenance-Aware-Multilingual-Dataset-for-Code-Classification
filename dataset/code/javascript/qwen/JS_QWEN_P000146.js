const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let dp = Array(r).fill(0).map(() => Array(c).fill(0));
        let maxSq = 0;
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if(mat[i][j]===1) {
                    if(i===0 || j===0) dp[i][j]=1;
                    else dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                    maxSq = Math.max(maxSq, dp[i][j]);
                }
            }
        }
        console.log(maxSq);
        rl.close();
    }
});
