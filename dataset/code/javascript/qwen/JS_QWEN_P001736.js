const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [n, k] = input.split(/\s+/).map(Number);
    function kthSymbol(n, k) {
        if (n === 1) return 0;
        let half = Math.pow(2, n-2);
        if (k <= half) return kthSymbol(n-1, k);
        else return 1 - kthSymbol(n-1, k-half);
    }
    console.log(kthSymbol(n, k));
    rl.close();
});
