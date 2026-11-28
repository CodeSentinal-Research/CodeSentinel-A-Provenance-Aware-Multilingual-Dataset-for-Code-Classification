const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = line.split(/\s+/).map(Number);
        function fact(x) {
            let f = 1;
            for(let i=2; i<=x; i++) f *= i;
            return f;
        }
        let prob = fact(n) / (fact(k) * fact(n-k)) / Math.pow(2, n);
        console.log(prob.toFixed(5));
        rl.close();
    }
});
