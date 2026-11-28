const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], t = lines[1];
        let m=s.length, n=t.length;
        let dp = Array.from({length:m+1}, ()=>new Array(n+1).fill(0));
        for(let i=0; i<=m; i++) dp[i][0] = 1;
        for(let i=1; i<=m; i++) {
            for(let j=1; j<=n; j++) {
                dp[i][j] = dp[i-1][j];
                if(s[i-1]===t[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        console.log(dp[m][n]);
        rl.close();
    }
});
