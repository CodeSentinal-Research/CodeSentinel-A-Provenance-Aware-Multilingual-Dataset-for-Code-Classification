const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, m] = line.split(/\s+/).map(BigInt);
        function gcd(a, b) { return b === 0n ? a : gcd(b, a % b); }
        function modInverse(a, m) {
            if (gcd(a, m) !== 1n) return -1n;
            // Extended Euclidean
            let m0 = m, t, q;
            let x0 = 0n, x1 = 1n;
            if (m === 1n) return 0n;
            while (a > 1n) {
                q = a / m;
                t = m;
                m = a % m;
                a = t;
                t = x0;
                x0 = x1 - q * x0;
                x1 = t;
            }
            if (x1 < 0n) x1 += m0;
            return x1;
        }
        console.log(modInverse(a, m).toString());
        rl.close();
    }
});
