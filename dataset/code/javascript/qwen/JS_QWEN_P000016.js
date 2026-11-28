const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const c = parseFloat(input.trim());
    console.log(((c * 9/5) + 32).toFixed(2));
    rl.close();
});
