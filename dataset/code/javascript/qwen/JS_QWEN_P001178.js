const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=r; i++) grid.push(lines[i].split(/\s+/).map(Number));
        let dp = Array.from({length:r}, ()=>new Array(c).fill(0));
        for(let i=0; i<r; i++) dp[i][0] = grid[i][0];
        for(let j=1; j<c; j++) {
            dp[0][j] = grid[0][j];
            for(let i=1; i<r; i++) {
                dp[i][j] = grid[i][j] + Math.max(dp[i-1][j], dp[i-1][j-1], i<r-1?dp[i+1][j-1]:0);
            }
        }
        let maxGold = 0;
        for(let i=0; i<r; i++) maxGold = Math.max(maxGold, dp[i][c-1]);
        console.log(maxGold);
        rl.close();
    }
});
