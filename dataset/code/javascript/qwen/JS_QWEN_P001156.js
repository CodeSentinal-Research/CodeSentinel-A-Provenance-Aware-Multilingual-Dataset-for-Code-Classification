const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [e, f] = line.split(/\s+/).map(Number);
        let dp = Array.from({length:e+1}, ()=>new Array(f+1).fill(Infinity));
        for(let i=1; i<=e; i++) {
            dp[i][1] = 1;
            for(let j=1; j<=f; j++) dp[1][j] = j;
        }
        for(let i=2; i<=e; i++) {
            for(let j=2; j<=f; j++) {
                let low=1, high=j, res=j;
                while(low<=high) {
                    let mid = Math.floor((low+high)/2);
                    let breakCase = dp[i-1][mid-1];
                    let noBreakCase = dp[i][j-mid];
                    let worst = 1 + Math.max(breakCase, noBreakCase);
                    if(breakCase > noBreakCase) high = mid-1;
                    else low = mid+1;
                    res = Math.min(res, worst);
                }
                dp[i][j] = res;
            }
        }
        console.log(dp[e][f]);
        rl.close();
    }
});
