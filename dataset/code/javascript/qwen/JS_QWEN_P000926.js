const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    console.log(n.toString(8));
    console.log(n.toString(16).toUpperCase());
    rl.close();
});
