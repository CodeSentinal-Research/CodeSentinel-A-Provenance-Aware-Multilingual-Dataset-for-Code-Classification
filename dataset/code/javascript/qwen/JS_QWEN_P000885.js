const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let s = n.toString().length;
    let sum = 0;
    let x = n;
    while (x > 0) {
        sum += Math.pow(x % 10, s);
        x = Math.trunc(x / 10);
    }
    console.log(sum === n ? "true" : "false");
    rl.close();
});
