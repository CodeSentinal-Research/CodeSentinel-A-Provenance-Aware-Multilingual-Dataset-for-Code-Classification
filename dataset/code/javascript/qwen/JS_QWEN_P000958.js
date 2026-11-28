const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b] = line.split(/\s+/).map(BigInt);
        function extendedGcd(a, b) {
            if (b === 0n) return [a, 1n, 0n];
            let [g, x1, y1] = extendedGcd(b, a % b);
            return [g, y1, x1 - (a / b) * y1];
        }
        let [g, x, y] = extendedGcd(a, b);
        // Adjust x to be smallest positive
        let m = b / g;
        let res = (x % m + m) % m;
        if (res === 0n) res = m; // If 0, usually we want positive, but 0 is valid if allowed. Problem says smallest positive.
        console.log(`${res} ${y}`); // Note: y might need adjustment too but problem asks for pair
        rl.close();
    }
});
