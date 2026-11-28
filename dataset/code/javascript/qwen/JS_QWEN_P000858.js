const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let pos = 0;
    while (n > 1) {
        n >>= 1;
        pos++;
    }
    console.log(pos + 1);
    rl.close();
});
