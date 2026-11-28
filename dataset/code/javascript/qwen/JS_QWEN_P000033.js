const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sum = 0;
    for(let i=2; i<=n; i+=2) sum += i;
    console.log(sum);
    rl.close();
});
