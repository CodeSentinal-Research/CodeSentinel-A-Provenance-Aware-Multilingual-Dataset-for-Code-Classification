const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, m] = line.split(/\s+/).map(BigInt);
        function gcd(a, b) { return b === 0n ? a : gcd(b, a % b); }
        let g = gcd(a, m);
        if (b % g !== 0n) console.log(-1);
        else {
            // Solve (a/g)x ≡ (b/g) (mod m/g)
            let a1 = a / g, b1 = b / g, m1 = m / g;
            function extendedGcd(a, b) {
                if (b === 0n) return [a, 1n, 0n];
                let [g, x1, y1] = extendedGcd(b, a % b);
                return [g, y1, x1 - (a / b) * y1];
            }
            let [_, x, _] = extendedGcd(a1, m1);
            let res = (x * b1) % m1;
            if (res < 0n) res += m1;
            console.log(res.toString());
        }
        rl.close();
    }
});
