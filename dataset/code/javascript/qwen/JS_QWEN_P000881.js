const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n === 0) { console.log(1); rl.close(); return; }
    console.log(Math.floor(Math.log10(n)) + 1);
    rl.close();
});
