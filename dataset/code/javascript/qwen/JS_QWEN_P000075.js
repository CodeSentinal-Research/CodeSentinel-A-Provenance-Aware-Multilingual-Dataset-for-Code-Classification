const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [r, h] = input.trim().split(/\s+/).map(Number);
    console.log((3.14159 * r*r * h).toFixed(2));
    rl.close();
});
