const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [x, y] = line.split(/\s+/).map(Number);
        let xor = x ^ y;
        let count = 0;
        while (xor) {
            count += xor & 1;
            xor >>= 1;
        }
        console.log(count);
        rl.close();
    }
});
