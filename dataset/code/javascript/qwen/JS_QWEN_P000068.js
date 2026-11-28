const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = parseFloat(input.trim());
    console.log((4 * s).toFixed(2));
    rl.close();
});
