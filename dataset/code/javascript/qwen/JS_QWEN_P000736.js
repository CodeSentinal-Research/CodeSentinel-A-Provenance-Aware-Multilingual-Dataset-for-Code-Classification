const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = line.split(/\s+/).map(Number);
        function kthSymbol(n, k) {
            if (n === 1) return 0;
            let half = Math.pow(2, n - 2);
            if (k <= half) return kthSymbol(n - 1, k);
            else return 1 - kthSymbol(n - 1, k - half);
        }
        console.log(kthSymbol(n, k));
        rl.close();
    }
});
