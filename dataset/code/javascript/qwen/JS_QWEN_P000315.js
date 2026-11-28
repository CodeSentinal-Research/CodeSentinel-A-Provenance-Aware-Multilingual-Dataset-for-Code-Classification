const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = 0;
    for(let c of s) res = res * 26 + (c.charCodeAt(0) - 64);
    console.log(res);
    rl.close();
});
