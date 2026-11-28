const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [a, d, n] = input.trim().split(/\s+/).map(Number);
    console.log(((n/2) * (2*a + (n-1)*d)).toFixed(2));
    rl.close();
});
