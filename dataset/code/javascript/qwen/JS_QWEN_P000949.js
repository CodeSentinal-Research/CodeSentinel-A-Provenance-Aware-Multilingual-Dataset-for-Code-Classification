const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let result = n;
    for(let i=2; i*i<=n; i++) {
        if(n % i === 0) {
            while(n % i === 0) n /= i;
            result -= result / i;
        }
    }
    if(n > 1) result -= result / n;
    console.log(result);
    rl.close();
});
