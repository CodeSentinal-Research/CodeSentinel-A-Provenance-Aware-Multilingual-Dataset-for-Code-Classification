const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = line.split(/\s+/).map(Number);
        if(n===1) console.log(k);
        else if(n===2) console.log(k*k);
        else {
            let same = k, diff = k*(k-1);
            for(let i=3; i<=n; i++) {
                let temp = diff;
                diff = (same+diff)*(k-1);
                same = temp;
            }
            console.log(same+diff);
        }
        rl.close();
    }
});
