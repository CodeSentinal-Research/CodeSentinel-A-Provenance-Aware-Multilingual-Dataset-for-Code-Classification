const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let factors = [];
    for(let i=1; i<=n; i++) {
        if(n % i === 0) factors.push(i);
    }
    console.log(factors.join(" "));
    rl.close();
});
