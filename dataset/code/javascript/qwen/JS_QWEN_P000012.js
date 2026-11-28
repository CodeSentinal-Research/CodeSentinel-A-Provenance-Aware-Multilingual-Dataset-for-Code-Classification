const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [p, r, t] = input.trim().split(/\s+/).map(Number);
    console.log((p * r * t) / 100);
    rl.close();
});
