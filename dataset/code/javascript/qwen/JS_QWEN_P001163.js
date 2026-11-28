const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const a = lines[0], b = lines[1], c = lines[2];
        let m=a.length, n=b.length, l=c.length;
        if(m+n !== l) { console.log("NO"); rl.close(); return; }
        let dp = Array.from({length:m+1}, ()=>new Array(n+1).fill(false));
        dp[0][0] = true;
        for(let i=0; i<=m; i++) {
            for(let j=0; j<=n; j++) {
                if(i>0 && dp[i-1][j] && a[i-1]===c[i+j-1]) dp[i][j] = true;
                if(j>0 && dp[i][j-1] && b[j-1]===c[i+j-1]) dp[i][j] = true;
            }
        }
        console.log(dp[m][n] ? "YES" : "NO");
        rl.close();
    }
});
