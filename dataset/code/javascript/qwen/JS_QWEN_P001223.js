const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if(n===0) { console.log(1); rl.close(); return; }
    let a=1, b=1;
    for(let i=2; i<=n; i++) {
        let t = a+b;
        a=b; b=t;
    }
    console.log(a+b);
    rl.close();
});
