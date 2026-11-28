const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sieve = new Array(n + 1).fill(true);
    sieve[0] = sieve[1] = false;
    for (let i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (let j = i * i; j <= n; j += i) sieve[j] = false;
        }
    }
    console.log(sieve.filter(x => x).length);
    rl.close();
});
