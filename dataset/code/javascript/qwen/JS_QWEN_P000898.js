const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [num, den] = line.split(/\s+/).map(Number);
        function gcd(a, b) { return b === 0 ? a : gcd(b, a % b); }
        let g = gcd(num, den);
        console.log(`${num/g} ${den/g}`);
        rl.close();
    }
});
