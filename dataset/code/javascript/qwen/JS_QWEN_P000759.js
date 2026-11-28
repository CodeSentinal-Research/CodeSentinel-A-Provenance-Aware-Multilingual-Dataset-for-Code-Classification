const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let mod = 10**9 + 7;
    function pow(x, n) {
        if (n === 0) return 1;
        let half = pow(x, Math.floor(n / 2)) % mod;
        let res = (half * half) % mod;
        if (n % 2 !== 0) res = (res * x) % mod;
        return res;
    }
    let evenPos = Math.ceil(n / 2);
    let oddPos = Math.floor(n / 2);
    let res = (pow(5, evenPos) * pow(4, oddPos)) % mod;
    console.log(res);
    rl.close();
});
