const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const total = (n * (n + 1)) / 2;
        const sum = arr.reduce((a, b) => a + b, 0);
        console.log(total - sum);
        rl.close();
    }
});
