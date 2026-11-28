const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const batteries = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = Math.floor(batteries.reduce((a,b)=>a+b, 0) / n);
        while (l < r) {
            let mid = Math.ceil((l + r) / 2);
            let total = 0;
            for (let b of batteries) total += Math.min(b, mid);
            if (total >= n * mid) l = mid;
            else r = mid - 1;
        }
        console.log(l);
        rl.close();
    }
});
