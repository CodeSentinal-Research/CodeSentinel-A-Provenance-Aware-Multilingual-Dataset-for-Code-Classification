const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = 0;
    for (let i = 0; i < 32; i++) {
        res <<= 1;
        res |= (n & 1);
        n >>= 1;
    }
    console.log(res >>> 0); // Unsigned shift to handle negative numbers correctly in JS
    rl.close();
});
