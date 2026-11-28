const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, amount] = lines[0].split(/\s+/).map(Number);
        const coins = lines[1].split(/\s+/).map(Number);
        let dp = new Array(amount+1).fill(0);
        dp[0] = 1;
        for(let coin of coins) {
            for(let i=coin; i<=amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        console.log(dp[amount]);
        rl.close();
    }
});
