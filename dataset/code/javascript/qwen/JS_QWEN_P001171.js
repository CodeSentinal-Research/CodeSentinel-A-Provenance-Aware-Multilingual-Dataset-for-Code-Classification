const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [r, c] = line.split(/\s+/).map(Number);
        let dp = Array.from({length:r}, ()=>new Array(c).fill(0));
        for(let i=0; i<r; i++) dp[i][0] = 1;
        for(let j=0; j<c; j++) dp[0][j] = 1;
        for(let i=1; i<r; i++) {
            for(let j=1; j<c; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        console.log(dp[r-1][c-1]);
        rl.close();
    }
});
