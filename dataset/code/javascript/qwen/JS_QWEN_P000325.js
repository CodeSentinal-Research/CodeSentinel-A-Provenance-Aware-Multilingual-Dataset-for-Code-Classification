const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const a = lines[0], b = lines[1];
        console.log(a === b ? -1 : Math.max(a.length, b.length));
        rl.close();
    }
});
