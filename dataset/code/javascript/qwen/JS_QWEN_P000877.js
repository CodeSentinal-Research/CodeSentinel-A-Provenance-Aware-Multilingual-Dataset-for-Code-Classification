const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [start, goal] = line.split(/\s+/).map(Number);
        let xor = start ^ goal;
        let count = 0;
        while (xor) {
            count += xor & 1;
            xor >>= 1;
        }
        console.log(count);
        rl.close();
    }
});
