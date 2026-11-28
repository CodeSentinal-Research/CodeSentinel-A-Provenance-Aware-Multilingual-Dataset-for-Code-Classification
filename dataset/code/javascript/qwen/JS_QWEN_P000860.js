const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n === 0) { console.log(1); rl.close(); return; }
    let mask = 1;
    while (mask <= n) mask <<= 1;
    mask -= 1;
    console.log(n ^ mask);
    rl.close();
});
