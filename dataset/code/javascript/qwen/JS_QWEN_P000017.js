const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const f = parseFloat(input.trim());
    console.log(((f - 32) * 5/9).toFixed(2));
    rl.close();
});
