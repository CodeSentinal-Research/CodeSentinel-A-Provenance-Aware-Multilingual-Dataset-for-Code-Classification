const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, r, p] = line.split(/\s+/).map(BigInt);
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
        // Lucas Theorem or Fermat's Little Theorem for inverse
        // Assuming p is prime
        function factMod(n, p) {
            let res = 1n;
            for(let i=2n; i<=n; i++) res = (res * i) % p;
            return res;
        }
        let num = factMod(n, p);
        let den = (factMod(r, p) * factMod(n-r, p)) % p;
        let invDen = modPow(den, p-2n, p);
        console.log((num * invDen) % p);
        rl.close();
    }
});
