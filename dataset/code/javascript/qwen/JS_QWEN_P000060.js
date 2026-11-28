const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let count = 0;
    let num = Math.abs(n);
    if(num === 0) count = 1;
    while(num > 0) {
        if((num % 10) % 2 === 0) count++;
        num = Math.floor(num / 10);
    }
    console.log(count);
    rl.close();
});
