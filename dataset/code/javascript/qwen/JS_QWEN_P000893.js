const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    let x = n;
    for (let i = 2; i * i <= x; i++) {
        if (x % i === 0) {
            res.push(i);
            while (x % i === 0) x /= i;
        }
    }
    if (x > 1) res.push(x);
    console.log(res.join(" "));
    rl.close();
});
