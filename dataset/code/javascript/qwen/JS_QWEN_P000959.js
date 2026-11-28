const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, c] = line.split(/\s+/).map(BigInt);
        function gcd(a, b) { return b === 0n ? a : gcd(b, a % b); }
        let g = gcd(a, b);
        console.log(c % g === 0n ? "true" : "false");
        rl.close();
    }
});
