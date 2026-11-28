const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let count = 0;
    let x = n;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    console.log(count);
    rl.close();
});
