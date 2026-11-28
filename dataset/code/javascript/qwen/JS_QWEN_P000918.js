const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n <= 1) console.log(1);
    else {
        let f = 1;
        for(let i=2; i<n; i++) f *= i;
        console.log(f);
    }
    rl.close();
});
