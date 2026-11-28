const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let p = 1;
    let x = Math.abs(n);
    if (x === 0) { console.log(0); rl.close(); return; }
    while (x > 0) {
        p *= x % 10;
        x = Math.trunc(x / 10);
    }
    console.log(p);
    rl.close();
});
