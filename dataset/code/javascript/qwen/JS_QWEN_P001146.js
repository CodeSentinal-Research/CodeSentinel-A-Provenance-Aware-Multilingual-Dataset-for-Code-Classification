const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [s1, s2] = line.split(/\s+/);
        let m=s1.length, n=s2.length;
        let dp = Array.from({length:m+1}, ()=>new Array(n+1).fill(0));
        for(let i=1; i<=m; i++) {
            for(let j=1; j<=n; j++) {
                if(s1[i-1]===s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
        console.log(dp[m][n]);
        rl.close();
    }
});
