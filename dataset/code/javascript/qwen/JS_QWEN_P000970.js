const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let t0 = 0, t1 = 1, t2 = 1;
    if (n === 0) { console.log(0); rl.close(); return; }
    if (n <= 2) { console.log(1); rl.close(); return; }
    let res = 0;
    for(let i=3; i<=n; i++) {
        res = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = res;
    }
    console.log(res);
    rl.close();
});
