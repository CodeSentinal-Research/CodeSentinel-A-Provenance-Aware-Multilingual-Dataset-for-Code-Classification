const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
function fact(n) { let f=1; for(let i=1; i<=n; i++) f*=i; return f; }
rl.on('line', (input) => {
    const [n, r] = input.trim().split(/\s+/).map(Number);
    console.log(fact(n) / (fact(r) * fact(n-r)));
    rl.close();
});
