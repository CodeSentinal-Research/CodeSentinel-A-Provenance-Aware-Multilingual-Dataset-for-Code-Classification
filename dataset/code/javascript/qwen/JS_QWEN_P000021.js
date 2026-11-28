const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let fact = 1;
    for(let i=1; i<=n; i++) fact *= i;
    console.log(fact);
    rl.close();
});
