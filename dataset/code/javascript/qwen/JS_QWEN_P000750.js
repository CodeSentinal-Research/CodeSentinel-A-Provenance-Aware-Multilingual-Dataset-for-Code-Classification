const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function lexOrder(curr, n) {
        if (curr > n) return;
        res.push(curr);
        for (let i = 0; i <= 9; i++) {
            if (curr * 10 + i > n) break;
            lexOrder(curr * 10 + i, n);
        }
    }
    for (let i = 1; i <= 9; i++) lexOrder(i, n);
    console.log(res.join("\n"));
    rl.close();
});
