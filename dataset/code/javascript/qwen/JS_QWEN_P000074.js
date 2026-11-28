const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const r = parseFloat(input.trim());
    console.log(((4/3) * 3.14159 * r*r*r).toFixed(2));
    rl.close();
});
