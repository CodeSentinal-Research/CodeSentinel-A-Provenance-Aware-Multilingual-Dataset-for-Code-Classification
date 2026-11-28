const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const text = lines[0], pattern = lines[1];
        let m=text.length, n=pattern.length;
        let dp = Array.from({length:m+1}, ()=>new Array(n+1).fill(false));
        dp[0][0] = true;
        for(let j=1; j<=n; j++) {
            if(pattern[j-1]==='*') dp[0][j] = dp[0][j-2];
        }
        for(let i=1; i<=m; i++) {
            for(let j=1; j<=n; j++) {
                if(pattern[j-1]===text[i-1] || pattern[j-1]==='.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(pattern[j-1]==='*') {
                    dp[i][j] = dp[i][j-2];
                    if(pattern[j-2]===text[i-1] || pattern[j-2]==='.') {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }
        console.log(dp[m][n] ? "YES" : "NO");
        rl.close();
    }
});
