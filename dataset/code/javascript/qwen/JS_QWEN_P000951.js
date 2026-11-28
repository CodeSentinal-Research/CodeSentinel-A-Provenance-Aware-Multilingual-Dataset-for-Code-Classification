const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let phi = Array(n+1).fill(0).map((_, i) => i);
    for(let i=2; i<=n; i++) {
        if(phi[i] === i) {
            for(let j=i; j<=n; j+=i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    let sum = 0;
    for(let i=1; i<=n; i++) sum += phi[i];
    console.log(sum);
    rl.close();
});
