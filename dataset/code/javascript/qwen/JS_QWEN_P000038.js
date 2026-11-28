const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [p, r, t] = input.trim().split(/\s+/).map(Number);
    const amount = p * Math.pow((1 + r/100), t);
    console.log((amount - p).toFixed(2));
    rl.close();
});
