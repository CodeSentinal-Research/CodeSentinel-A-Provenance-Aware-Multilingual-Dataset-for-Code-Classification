const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let dp = new Array(n+1).fill(0);
    dp[0] = 1;
    for(let i=1; i<=n; i++) {
        if(s[i-1]!=='0') dp[i] += dp[i-1];
        if(i>1) {
            let two = parseInt(s.substring(i-2, i));
            if(two>=10 && two<=26) dp[i] += dp[i-2];
        }
    }
    console.log(dp[n]);
    rl.close();
});
