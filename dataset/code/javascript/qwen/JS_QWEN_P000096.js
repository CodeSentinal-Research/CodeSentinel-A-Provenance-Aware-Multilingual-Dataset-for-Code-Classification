const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sum = 0, prod = 1;
    let num = n;
    while(num > 0) {
        const d = num % 10;
        sum += d;
        prod *= d;
        num = Math.floor(num/10);
    }
    console.log(sum === prod ? "Spy" : "Not Spy");
    rl.close();
});
