const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let s = n.toString();
    let max = -1, min = 10;
    for(let c of s) {
        let d = parseInt(c);
        if(d > max) max = d;
        if(d < min) min = d;
    }
    console.log(`${max} ${min}`);
    rl.close();
});
