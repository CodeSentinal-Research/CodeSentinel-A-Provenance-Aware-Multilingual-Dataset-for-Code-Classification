const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    const s = n.toString();
    const len = s.length;
    let sum = 0;
    for(let char of s) sum += Math.pow(parseInt(char), len);
    console.log(sum === n ? "Armstrong" : "Not Armstrong");
    rl.close();
});
