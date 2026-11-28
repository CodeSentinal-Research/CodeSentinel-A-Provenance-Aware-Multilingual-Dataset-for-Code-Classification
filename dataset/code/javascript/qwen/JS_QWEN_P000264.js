const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {};
    for(let c of s) count[c]=(count[c]||0)+1;
    for(let c in count) console.log(`${c} ${count[c]}`);
    rl.close();
});
