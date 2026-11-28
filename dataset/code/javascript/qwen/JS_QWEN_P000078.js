const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const d = parseInt(input.trim());
    const y = Math.floor(d / 365);
    const w = Math.floor((d % 365) / 7);
    const days = d % 7;
    console.log(`${y} ${w} ${days}`);
    rl.close();
});
