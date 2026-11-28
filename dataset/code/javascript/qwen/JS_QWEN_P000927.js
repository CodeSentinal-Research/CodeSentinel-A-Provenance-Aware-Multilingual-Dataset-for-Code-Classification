const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const parts = lines[0].split(/\s+/);
        const numStr = parts[0];
        const baseA = parseInt(parts[1]);
        const baseB = parseInt(parts[2]);
        const decimal = parseInt(numStr, baseA);
        console.log(decimal.toString(baseB).toUpperCase());
        rl.close();
    }
});
