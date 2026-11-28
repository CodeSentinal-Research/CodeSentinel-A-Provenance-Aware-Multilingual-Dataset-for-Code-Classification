const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, r] = line.split(/\s+/).map(Number);
        function fact(x) {
            let f = 1;
            for(let i=2; i<=x; i++) f *= i;
            return f;
        }
        console.log(fact(n) / (fact(r) * fact(n-r)));
        rl.close();
    }
});
