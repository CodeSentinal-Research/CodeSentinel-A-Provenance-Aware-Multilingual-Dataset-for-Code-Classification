const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
function fact(n) { let f=1; for(let i=1; i<=n; i++) f*=i; return f; }
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sum = 0;
    let num = n;
    while(num > 0) {
        sum += fact(num % 10);
        num = Math.floor(num / 10);
    }
    console.log(sum === n ? "Strong" : "Not Strong");
    rl.close();
});
