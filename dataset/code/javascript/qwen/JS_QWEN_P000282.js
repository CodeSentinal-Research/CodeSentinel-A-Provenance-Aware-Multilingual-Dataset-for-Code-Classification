const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0], s2 = lines[1];
        let m=s1.length, n=s2.length;
        let dp = Array(m+1).fill(0).map(()=>Array(n+1).fill(0));
        let maxLen=0, endIdx=0;
        for(let i=1; i<=m; i++) {
            for(let j=1; j<=n; j++) {
                if(s1[i-1]===s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j]>maxLen) { maxLen=dp[i][j]; endIdx=i; }
                }
            }
        }
        console.log(s1.substring(endIdx-maxLen, endIdx));
        rl.close();
    }
});
