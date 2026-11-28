const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const prices = lines[1].split(/\s+/).map(Number);
        let profit = 0;
        for(let i=1; i<n; i++) {
            if(prices[i]>prices[i-1]) profit += prices[i]-prices[i-1];
        }
        console.log(profit);
        rl.close();
    }
});
