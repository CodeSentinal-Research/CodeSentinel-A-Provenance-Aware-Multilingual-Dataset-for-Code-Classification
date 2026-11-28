const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
function isPrime(n) {
    if(n<=1) return false;
    for(let i=2; i*i<=n; i++) if(n%i===0) return false;
    return true;
}
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sum = 0;
    for(let i=2; i<=n; i++) if(isPrime(i)) sum += i;
    console.log(sum);
    rl.close();
});
