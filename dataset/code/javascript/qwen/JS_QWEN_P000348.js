const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let mod = 10**9+7;
    let dp = Array(n+1).fill(0).map(()=>Array(3).fill(0).map(()=>Array(2).fill(0)));
    dp[0][0][0] = 1;
    for(let i=1; i<=n; i++) {
        for(let a=0; a<3; a++) {
            for(let l=0; l<3; l++) {
                dp[i][a][l] = dp[i-1][a][l]; // P
                if(a>0) dp[i][a][l] = (dp[i][a][l] + dp[i-1][a-1][l]) % mod; // A
                if(l>0) dp[i][a][l] = (dp[i][a][l] + dp[i-1][a][l-1]) % mod; // L
            }
        }
    }
    let res = 0;
    for(let a=0; a<3; a++) for(let l=0; l<3; l++) res = (res + dp[n][a][l]) % mod;
    console.log(res);
    rl.close();
});
