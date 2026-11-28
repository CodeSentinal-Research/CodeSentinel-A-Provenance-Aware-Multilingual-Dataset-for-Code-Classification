const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [root, x] = lines[0].split(/\s+/).map(Number);
        console.log(x);
        rl.close();
    }
});
