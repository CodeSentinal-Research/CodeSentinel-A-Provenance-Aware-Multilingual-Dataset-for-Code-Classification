const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = 0, prev = '', len = 0;
    for (let c of s) {
        if (c === prev) len++;
        else {
            prev = c; len = 1;
        }
        if (len >= 2) count++;
    }
    console.log(count);
    rl.close();
});
