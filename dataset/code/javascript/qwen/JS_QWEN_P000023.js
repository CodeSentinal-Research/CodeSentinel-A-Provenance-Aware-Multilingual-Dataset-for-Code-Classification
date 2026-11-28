const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let a = 0, b = 1;
    let res = [];
    for(let i=0; i<n; i++) {
        res.push(a);
        let temp = a + b;
        a = b;
        b = temp;
    }
    console.log(res.join(" "));
    rl.close();
});
