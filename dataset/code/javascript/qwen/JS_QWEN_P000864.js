const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let xor = 0;
        for (let i = 0; i <= n; i++) xor ^= i;
        for (let x of nums) xor ^= x;
        console.log(xor);
        rl.close();
    }
});
