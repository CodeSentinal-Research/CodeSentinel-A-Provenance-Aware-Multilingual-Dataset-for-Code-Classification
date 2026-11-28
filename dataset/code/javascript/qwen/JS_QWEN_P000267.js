const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const s = lines[0];
        const oldC = lines[1];
        const newC = lines[2];
        console.log(s.split(oldC).join(newC));
        rl.close();
    }
});
