const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [scored, total] = input.trim().split(/\s+/).map(Number);
    console.log(((scored / total) * 100).toFixed(2));
    rl.close();
});
