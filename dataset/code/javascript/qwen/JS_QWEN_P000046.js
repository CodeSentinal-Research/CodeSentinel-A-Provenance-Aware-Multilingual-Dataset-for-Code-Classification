const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [a, b] = input.trim().split(/\s+/).map(Number);
    console.log(a % b === 0 ? "Divisible" : "Not Divisible");
    rl.close();
});
