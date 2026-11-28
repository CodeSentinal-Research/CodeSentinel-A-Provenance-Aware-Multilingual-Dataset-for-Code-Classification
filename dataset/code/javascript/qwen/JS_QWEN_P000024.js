const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sum = 0;
    let num = Math.abs(n);
    if (num === 0) sum = 0;
    while(num > 0) {
        sum += num % 10;
        num = Math.floor(num / 10);
    }
    console.log(sum);
    rl.close();
});
