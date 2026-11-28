const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n === 0) { console.log(32); rl.close(); return; }
    let count = 0;
    for (let i = 31; i >= 0; i--) {
        if ((n >> i) & 1) break;
        count++;
    }
    console.log(count);
    rl.close();
});
