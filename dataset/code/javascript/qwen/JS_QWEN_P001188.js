const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const prices = lines[1].split(/\s+/).map(Number);
        let buy1=-Infinity, sell1=0, buy2=-Infinity, sell2=0;
        for(let p of prices) {
            buy1 = Math.max(buy1, -p);
            sell1 = Math.max(sell1, buy1+p);
            buy2 = Math.max(buy2, sell1-p);
            sell2 = Math.max(sell2, buy2+p);
        }
        console.log(sell2);
        rl.close();
    }
});
