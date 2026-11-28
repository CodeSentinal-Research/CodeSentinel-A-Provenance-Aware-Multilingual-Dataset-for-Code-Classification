const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let xor = 0;
        for (let x of nums) xor ^= x;
        let diff = xor & -xor;
        let a = 0, b = 0;
        for (let x of nums) {
            if (x & diff) a ^= x;
            else b ^= x;
        }
        console.log(`${Math.min(a,b)} ${Math.max(a,b)}`);
        rl.close();
    }
});
