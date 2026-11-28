const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [a, b, c] = input.trim().split(/\s+/).map(Number);
    console.log(((a + b + c) / 3).toFixed(2));
    rl.close();
});
