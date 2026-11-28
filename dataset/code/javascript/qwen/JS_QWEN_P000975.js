const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [x1, y1, x2, y2] = line.split(/\s+/).map(Number);
        console.log(`${(x1+x2)/2} ${(y1+y2)/2}`);
        rl.close();
    }
});
