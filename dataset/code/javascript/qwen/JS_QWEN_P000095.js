const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    const sq = n * n;
    let sum = 0;
    let num = sq;
    while(num > 0) { sum += num%10; num = Math.floor(num/10); }
    console.log(sum === n ? "Neon" : "Not Neon");
    rl.close();
});
