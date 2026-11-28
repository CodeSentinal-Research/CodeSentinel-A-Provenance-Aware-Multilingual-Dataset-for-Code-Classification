const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, m] = line.split(/\s+/).map(BigInt);
        function modPow(base, exp, mod) {
            let res = 1n;
            base %= mod;
            while (exp > 0n) {
                if (exp % 2n === 1n) res = (res * base) % mod;
                base = (base * base) % mod;
                exp /= 2n;
            }
            return res;
        }
        console.log(modPow(a, b, m).toString());
        rl.close();
    }
});
