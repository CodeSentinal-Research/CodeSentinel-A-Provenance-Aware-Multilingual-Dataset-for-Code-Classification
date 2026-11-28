const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let count = 0;
    let used = new Array(n+1).fill(false);
    function solve(pos) {
        if (pos > n) {
            count++;
            return;
        }
        for (let i = 1; i <= n; i++) {
            if (!used[i] && (i % pos === 0 || pos % i === 0)) {
                used[i] = true;
                solve(pos + 1);
                used[i] = false;
            }
        }
    }
    solve(1);
    console.log(count);
    rl.close();
});
