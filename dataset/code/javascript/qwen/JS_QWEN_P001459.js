const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let present = new Array(n + 2).fill(false);
        for (let x of nums) {
            if (x > 0 && x <= n) present[x] = true;
        }
        for (let i = 1; i <= n + 1; i++) {
            if (!present[i]) { console.log(i); rl.close(); return; }
        }
        rl.close();
    }
});
