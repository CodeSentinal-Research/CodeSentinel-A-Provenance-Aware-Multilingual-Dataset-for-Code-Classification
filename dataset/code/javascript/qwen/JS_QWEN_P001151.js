const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let start=0, maxLen=1;
    let dp = Array.from({length:n}, ()=>new Array(n).fill(false));
    for(let i=n-1; i>=0; i--) {
        for(let j=i; j<n; j++) {
            if(s[i]===s[j] && (j-i<3 || dp[i+1][j-1])) {
                dp[i][j] = true;
                if(j-i+1 > maxLen) {
                    start = i;
                    maxLen = j-i+1;
                }
            }
        }
    }
    console.log(s.substring(start, start+maxLen));
    rl.close();
});
