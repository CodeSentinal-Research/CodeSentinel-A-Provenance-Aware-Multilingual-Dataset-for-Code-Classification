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
    console.log(phi.slice(1).join(" "));
    rl.close();
});
