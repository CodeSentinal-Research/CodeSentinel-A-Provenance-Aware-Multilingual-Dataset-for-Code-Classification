const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, fee] = lines[0].split(/\s+/).map(Number);
        const prices = lines[1].split(/\s+/).map(Number);
        let hold=-Infinity, cash=0;
        for(let p of prices) {
            let prevCash = cash;
            cash = Math.max(cash, hold+p);
            hold = Math.max(hold, prevCash-p-fee);
        }
        console.log(cash);
        rl.close();
    }
});
