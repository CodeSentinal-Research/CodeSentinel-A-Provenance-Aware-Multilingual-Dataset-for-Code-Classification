const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, amount] = lines[0].split(/\s+/).map(Number);
        const coins = lines[1].split(/\s+/).map(Number);
        let dp = new Array(amount+1).fill(Infinity);
        dp[0] = 0;
        for(let coin of coins) {
            for(let i=coin; i<=amount; i++) {
                dp[i] = Math.min(dp[i], dp[i-coin]+1);
            }
        }
        console.log(dp[amount] === Infinity ? -1 : dp[amount]);
        rl.close();
    }
});
