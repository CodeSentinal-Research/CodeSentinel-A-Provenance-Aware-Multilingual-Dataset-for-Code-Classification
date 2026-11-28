const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sq = n * n;
    let s = 0;
    while (sq > 0) {
        s += sq % 10;
        sq = Math.trunc(sq / 10);
    }
    console.log(s === n ? "true" : "false");
    rl.close();
});
