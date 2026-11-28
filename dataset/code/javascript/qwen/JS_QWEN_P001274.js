const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, coins] = lines[0].split(/\s+/).map(Number);
        const costs = lines[1].split(/\s+/).map(Number);
        
        costs.sort((a,b)=>a-b);
        let count=0;
        for(let c of costs) {
            if(coins>=c) { coins-=c; count++; }
            else break;
        }
        console.log(count);
        rl.close();
    }
});
