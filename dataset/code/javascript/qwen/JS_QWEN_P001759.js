const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let mod = 10**9 + 7;
    function pow(base, exp) {
        if (exp === 0) return 1;
        let half = pow(base, Math.floor(exp / 2)) % mod;
        let res = (half * half) % mod;
        if (exp % 2 !== 0) res = (res * base) % mod;
        return res;
    }
    let evenPos = Math.ceil(n / 2);
    let oddPos = Math.floor(n / 2);
    let res = (pow(5, evenPos) * pow(4, oddPos)) % mod;
    console.log(res);
    rl.close();
});
