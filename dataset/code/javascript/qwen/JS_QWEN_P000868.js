const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let total = 0;
        for (let i = 0; i < 32; i++) {
            let count = 0;
            for (let x of nums) {
                if (x & (1 << i)) count++;
            }
            total += count * (n - count);
        }
        console.log(total);
        rl.close();
    }
});
