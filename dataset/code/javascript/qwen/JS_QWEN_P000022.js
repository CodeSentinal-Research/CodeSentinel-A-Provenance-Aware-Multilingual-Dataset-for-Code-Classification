const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let isPrime = true;
    if (n <= 1) isPrime = false;
    for(let i=2; i*i<=n; i++) {
        if(n % i === 0) { isPrime = false; break; }
    }
    console.log(isPrime ? "Prime" : "Not Prime");
    rl.close();
});
