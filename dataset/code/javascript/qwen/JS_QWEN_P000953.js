const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, n] = line.split(/\s+/).map(BigInt);
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
        // Calculate Phi(n) first
        let temp = n;
        let phi = n;
        for(let i=2n; i*i<=temp; i++) {
            if(temp % i === 0n) {
                while(temp % i === 0n) temp /= i;
                phi -= phi / i;
            }
        }
        if(temp > 1n) phi -= phi / temp;
        
        console.log(modPow(a, phi, n).toString());
        rl.close();
    }
});
