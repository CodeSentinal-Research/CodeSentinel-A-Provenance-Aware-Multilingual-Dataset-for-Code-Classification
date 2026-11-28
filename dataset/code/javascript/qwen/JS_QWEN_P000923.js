const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n === 0) { console.log(1); rl.close(); return; }
    let count = 10;
    for(let i=2; i<=n; i++) {
        count += 9 * factorial(9) / factorial(10-i);
    }
    function factorial(x) {
        let f = 1;
        for(let i=2; i<=x; i++) f *= i;
        return f;
    }
    console.log(count);
    rl.close();
});
