const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const a = lines[0];
        const b = lines[1];
        const sum = BigInt('0b' + a) + BigInt('0b' + b);
        console.log(sum.toString(2));
        rl.close();
    }
});
