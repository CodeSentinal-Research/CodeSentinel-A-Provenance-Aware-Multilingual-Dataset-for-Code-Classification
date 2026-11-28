const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    // Catalan Number C(n) = (2n)! / ((n+1)! n!)
    function fact(x) {
        let f = 1;
        for(let i=2; i<=x; i++) f *= i;
        return f;
    }
    console.log(fact(2*n) / (fact(n+1) * fact(n)));
    rl.close();
});
