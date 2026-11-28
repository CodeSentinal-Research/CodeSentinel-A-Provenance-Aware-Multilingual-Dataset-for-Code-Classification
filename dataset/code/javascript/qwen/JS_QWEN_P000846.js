const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const quantities = lines[1].split(/\s+/).map(Number);
        
        let l = 1, r = Math.max(...quantities);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let stores = 0;
            for (let q of quantities) stores += Math.ceil(q / mid);
            if (stores > n) l = mid + 1;
            else r = mid;
        }
        console.log(l);
        rl.close();
    }
});
