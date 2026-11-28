const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let triangle = [];
        for(let i=1; i<=n; i++) triangle.push(lines[i].split(/\s+/).map(Number));
        let dp = triangle[n-1].slice();
        for(let i=n-2; i>=0; i--) {
            for(let j=0; j<=i; j++) {
                dp[j] = triangle[i][j] + Math.min(dp[j], dp[j+1]);
            }
        }
        console.log(dp[0]);
        rl.close();
    }
});
