const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b] = line.split(/\s+/).map(Number);
        function gcd(a, b) { return b === 0 ? a : gcd(b, a % b); }
        console.log((a * b) / gcd(a, b));
        rl.close();
    }
});
