const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const x = parseInt(input.trim());
    if (x < 2) { console.log(x); rl.close(); return; }
    let l = 1, r = x, res = 0;
    while (l <= r) {
        let m = Math.floor((l + r) / 2);
        if (m <= x / m) { res = m; l = m + 1; }
        else r = m - 1;
    }
    console.log(res);
    rl.close();
});
