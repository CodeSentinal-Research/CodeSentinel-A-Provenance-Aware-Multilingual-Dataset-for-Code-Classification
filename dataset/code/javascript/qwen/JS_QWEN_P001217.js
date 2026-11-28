const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let isPal = Array.from({length: n}, ()=>new Array(n).fill(false));
    
    for(let i=0; i<n; i++) isPal[i][i] = true;
    for(let i=0; i<n-1; i++) isPal[i][i+1] = (s[i]===s[i+1]);
    
    for(let len=3; len<=n; len++) {
        for(let i=0; i<=n-len; i++) {
            let j = i+len-1;
            isPal[i][j] = (s[i]===s[j] && isPal[i+1][j-1]);
        }
    }
    
    let dp = new Array(n).fill(Infinity);
    for(let i=0; i<n; i++) {
        if(isPal[0][i]) { dp[i]=0; continue; }
        for(let j=1; j<=i; j++) {
            if(isPal[j][i]) dp[i] = Math.min(dp[i], dp[j-1]+1);
        }
    }
    console.log(dp[n-1]);
    rl.close();
});
