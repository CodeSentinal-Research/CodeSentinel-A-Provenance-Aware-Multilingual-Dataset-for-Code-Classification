const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [left, right] = line.split(/\s+/).map(Number);
        while (left < right) {
            right = right & (right - 1);
        }
        console.log(left & right);
        rl.close();
    }
});
