const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let r=0, d=0;
    for(let c of s) c==='R'?r++:d++;
    console.log(r>d ? "Radiant" : "Dire");
    rl.close();
});
