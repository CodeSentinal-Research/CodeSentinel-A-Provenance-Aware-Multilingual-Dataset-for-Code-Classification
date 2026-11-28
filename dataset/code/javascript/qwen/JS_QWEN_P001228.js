const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [d, f, s] = lines[0].split(/\s+/).map(Number);
        let dp = Array.from({length: d+1}, ()=>new Array(s+1).fill(0));
        dp[0][0] = 1;
        for(let i=1; i<=d; i++) {
            for(let j=1; j<=s; j++) {
                for(let k=1; k<=f; k++) {
                    if(j-k>=0) dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        console.log(dp[d][s]);
        rl.close();
    }
});
