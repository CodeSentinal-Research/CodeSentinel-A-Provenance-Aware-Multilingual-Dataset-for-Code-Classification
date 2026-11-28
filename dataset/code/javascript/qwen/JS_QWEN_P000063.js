const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
function isPrime(n) {
    if(n<=1) return false;
    for(let i=2; i*i<=n; i++) if(n%i===0) return false;
    return true;
}
rl.on('line', (input) => {
    const [l, r] = input.trim().split(/\s+/).map(Number);
    let res = [];
    for(let i=l; i<=r; i++) if(isPrime(i)) res.push(i);
    console.log(res.join(" "));
    rl.close();
});
