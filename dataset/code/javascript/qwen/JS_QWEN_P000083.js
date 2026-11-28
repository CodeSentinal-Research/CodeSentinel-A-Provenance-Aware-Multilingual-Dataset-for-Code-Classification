const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [a, b, c] = input.trim().split(/\s+/).map(Number);
    console.log(Math.max(a, b, c));
    rl.close();
});
