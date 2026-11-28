const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = line.split(/\s+/).map(Number);
        // Stars and Bars: C(n+k-1, k-1)
        function fact(x) {
            let f = 1;
            for(let i=2; i<=x; i++) f *= i;
            return f;
        }
        let total = n + k - 1;
        let choose = k - 1;
        console.log(fact(total) / (fact(choose) * fact(total - choose)));
        rl.close();
    }
});
