const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const bin = input.trim();
    console.log(parseInt(bin, 2));
    rl.close();
});
