const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [b, h] = input.trim().split(/\s+/).map(Number);
    console.log((0.5 * b * h).toFixed(2));
    rl.close();
});
