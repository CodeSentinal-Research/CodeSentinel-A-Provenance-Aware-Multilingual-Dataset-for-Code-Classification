const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [l, b] = input.trim().split(/\s+/).map(Number);
    console.log((2 * (l + b)).toFixed(2));
    rl.close();
});
