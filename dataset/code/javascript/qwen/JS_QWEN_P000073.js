const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [l, b, h] = input.trim().split(/\s+/).map(Number);
    console.log((l*b*h).toFixed(2));
    rl.close();
});
