const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let s = 0;
    let x = Math.abs(n);
    while (x > 0) {
        s += x % 10;
        x = Math.trunc(x / 10);
    }
    console.log(s);
    rl.close();
});
