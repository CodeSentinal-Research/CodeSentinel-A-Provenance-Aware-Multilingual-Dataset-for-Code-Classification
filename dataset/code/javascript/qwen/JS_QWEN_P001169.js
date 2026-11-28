const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let dungeon = [];
        for(let i=1; i<=r; i++) dungeon.push(lines[i].split(/\s+/).map(Number));
        let dp = Array.from({length:r}, ()=>new Array(c).fill(Infinity));
        dp[r-1][c-1] = Math.max(1, 1-dungeon[r-1][c-1]);
        for(let i=r-2; i>=0; i--) dp[i][c-1] = Math.max(1, dp[i+1][c-1]-dungeon[i][c-1]);
        for(let j=c-2; j>=0; j--) dp[r-1][j] = Math.max(1, dp[r-1][j+1]-dungeon[r-1][j]);
        for(let i=r-2; i>=0; i--) {
            for(let j=c-2; j>=0; j--) {
                dp[i][j] = Math.max(1, Math.min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
            }
        }
        console.log(dp[0][0]);
        rl.close();
    }
});
