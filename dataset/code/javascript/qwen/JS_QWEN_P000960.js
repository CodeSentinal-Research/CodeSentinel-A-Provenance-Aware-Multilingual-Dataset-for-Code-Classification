const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, c] = line.split(/\s+/).map(BigInt);
        function gcd(a, b) { return b === 0n ? a : gcd(b, a % b); }
        function extendedGcd(a, b) {
            if (b === 0n) return [a, 1n, 0n];
            let [g, x1, y1] = extendedGcd(b, a % b);
            return [g, y1, x1 - (a / b) * y1];
        }
        let g = gcd(a, b);
        if (c % g !== 0n) console.log(-1);
        else {
            let [_, x, y] = extendedGcd(a, b);
            let factor = c / g;
            console.log(`${x * factor} ${y * factor}`);
        }
        rl.close();
    }
});
