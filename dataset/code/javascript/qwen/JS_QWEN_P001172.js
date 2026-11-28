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
        if(grid[0][0]===0) dp[0][0] = 1;
        for(let i=1; i<r; i++) dp[i][0] = grid[i][0]===0 ? dp[i-1][0] : 0;
        for(let j=1; j<c; j++) dp[0][j] = grid[0][j]===0 ? dp[0][j-1] : 0;
        for(let i=1; i<r; i++) {
            for(let j=1; j<c; j++) {
                if(grid[i][j]===0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        console.log(dp[r-1][c-1]);
        rl.close();
    }
});
