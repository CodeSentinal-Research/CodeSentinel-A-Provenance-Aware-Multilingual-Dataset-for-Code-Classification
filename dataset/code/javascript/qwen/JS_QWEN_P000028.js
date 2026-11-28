const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [x, n] = input.trim().split(/\s+/).map(Number);
    console.log(Math.pow(x, n));
    rl.close();
});
