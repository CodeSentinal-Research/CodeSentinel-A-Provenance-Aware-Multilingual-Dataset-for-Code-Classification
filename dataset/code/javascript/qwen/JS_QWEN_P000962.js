const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b] = line.split(/\s+/).map(BigInt);
        console.log((a * b - a - b).toString());
        rl.close();
    }
});
