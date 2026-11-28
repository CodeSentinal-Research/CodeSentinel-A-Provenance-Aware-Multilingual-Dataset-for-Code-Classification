const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, w] = lines[0].split(/\s+/).map(Number);
        let items = [];
        for(let i=1; i<=n; i++) {
            const [wt, val] = lines[i].split(/\s+/).map(Number);
            items.push([wt, val]);
        }
        let dp = new Array(w+1).fill(0);
        for(let [wt, val] of items) {
            for(let j=w; j>=wt; j--) {
                dp[j] = Math.max(dp[j], dp[j-wt]+val);
            }
        }
        console.log(dp[w]);
        rl.close();
    }
});
