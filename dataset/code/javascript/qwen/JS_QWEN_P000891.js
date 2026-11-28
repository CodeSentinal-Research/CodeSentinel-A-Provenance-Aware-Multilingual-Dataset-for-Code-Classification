const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let next = n + 1;
    while (true) {
        let isPrime = true;
        for (let i = 2; i * i <= next; i++) {
            if (next % i === 0) { isPrime = false; break; }
        }
        if (isPrime) { console.log(next); rl.close(); return; }
        next++;
    }
});
