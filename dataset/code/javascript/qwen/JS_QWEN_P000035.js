const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if(n <= 1) { console.log("Not Perfect"); rl.close(); return; }
    let sum = 1;
    for(let i=2; i*i<=n; i++) {
        if(n % i === 0) {
            sum += i;
            if(i !== n/i) sum += n/i;
        }
    }
    console.log(sum === n ? "Perfect" : "Not Perfect");
    rl.close();
});
