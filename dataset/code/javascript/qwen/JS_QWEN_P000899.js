const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    console.log(n % 3 === 0 ? "true" : "false");
    rl.close();
});
