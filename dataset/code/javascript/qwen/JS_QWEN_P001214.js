const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let dp = Array.from({length: n}, ()=>new Array(n).fill(Infinity));
    
    for(let i=0; i<n; i++) dp[i][i] = 1;
    
    for(let len=2; len<=n; len++) {
        for(let i=0; i<=n-len; i++) {
            let j = i+len-1;
            if(s[i]===s[j]) {
                dp[i][j] = (len===2) ? 1 : dp[i+1][j-1];
            } else {
                dp[i][j] = len;
                for(let k=i; k<j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    console.log(dp[0][n-1]);
    rl.close();
});
