const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    console.log(input.trim().replace(/\b\w/g, c => c.toUpperCase()));
    rl.close();
});
