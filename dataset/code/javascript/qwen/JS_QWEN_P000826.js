const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let l = 1, r = n;
    while (l <= r) {
        let m = Math.floor((l + r) / 2);
        if (m * (m + 1) / 2 <= n) l = m + 1;
        else r = m - 1;
    }
    console.log(r);
    rl.close();
});
