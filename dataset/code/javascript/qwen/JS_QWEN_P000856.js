const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n === 0) { console.log(32); rl.close(); return; }
    let count = 0;
    while ((n & 1) === 0) {
        count++;
        n >>= 1;
    }
    console.log(count);
    rl.close();
});
