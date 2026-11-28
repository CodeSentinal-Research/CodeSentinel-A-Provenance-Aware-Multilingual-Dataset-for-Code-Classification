const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [a, r, n] = input.trim().split(/\s+/).map(Number);
    if(r === 1) console.log((a*n).toFixed(2));
    else console.log((a * (Math.pow(r, n) - 1) / (r - 1)).toFixed(2));
    rl.close();
});
