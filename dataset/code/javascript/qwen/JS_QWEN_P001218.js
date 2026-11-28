const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const n = parseInt(lines[1]);
        let wordSet = new Set();
        for(let i=2; i<2+n; i++) wordSet.add(lines[i]);
        
        let dp = new Array(s.length+1).fill(false);
        dp[0] = true;
        for(let i=1; i<=s.length; i++) {
            for(let j=0; j<i; j++) {
                if(dp[j] && wordSet.has(s.substring(j,i))) {
                    dp[i] = true; break;
                }
            }
        }
        console.log(dp[s.length] ? "YES" : "NO");
        rl.close();
    }
});
