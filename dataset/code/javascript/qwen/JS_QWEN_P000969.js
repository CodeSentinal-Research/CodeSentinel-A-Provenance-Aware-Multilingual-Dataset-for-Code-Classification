const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let a = 0, b = 1;
    if (n === 0) { console.log(0); rl.close(); return; }
    if (n === 1) { console.log(1); rl.close(); return; }
    for(let i=2; i<=n; i++) {
        let t = a + b;
        a = b;
        b = t;
    }
    console.log(b);
    rl.close();
});
