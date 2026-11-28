const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let dp = Array(r).fill(0).map(()=>Array(c).fill(0));
        dp[0][0] = mat[0][0];
        for(let i=1; i<r; i++) dp[i][0] = dp[i-1][0]+mat[i][0];
        for(let j=1; j<c; j++) dp[0][j] = dp[0][j-1]+mat[0][j];
        for(let i=1; i<r; i++) {
            for(let j=1; j<c; j++) {
                dp[i][j] = mat[i][j] + Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
        console.log(dp[r-1][c-1]);
        rl.close();
    }
});
