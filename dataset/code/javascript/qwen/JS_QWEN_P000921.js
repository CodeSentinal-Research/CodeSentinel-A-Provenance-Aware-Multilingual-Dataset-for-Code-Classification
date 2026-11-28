const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let count = new Array(10).fill(0);
    let s = n.toString();
    for(let c of s) count[parseInt(c)]++;
    console.log(count.join(" "));
    rl.close();
});
