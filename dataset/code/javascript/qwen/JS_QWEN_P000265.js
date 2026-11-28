const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let seen = new Set(), res = [];
    for(let c of s) {
        if(!seen.has(c)) { seen.add(c); res.push(c); }
    }
    console.log(res.join(''));
    rl.close();
});
