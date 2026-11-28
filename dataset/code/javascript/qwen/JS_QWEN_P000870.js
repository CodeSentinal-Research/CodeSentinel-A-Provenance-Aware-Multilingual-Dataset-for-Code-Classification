const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b] = line.split(/\s+/).map(Number);
        while (b !== 0) {
            let carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        console.log(a);
        rl.close();
    }
});
