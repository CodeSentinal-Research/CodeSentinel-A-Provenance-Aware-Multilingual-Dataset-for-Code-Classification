const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let count = 0;
    let cols = new Array(n).fill(false);
    let diag1 = new Array(2*n).fill(false);
    let diag2 = new Array(2*n).fill(false);
    
    function solve(row) {
        if (row === n) {
            count++;
            return;
        }
        for (let col = 0; col < n; col++) {
            if (!cols[col] && !diag1[row+col] && !diag2[row-col+n]) {
                cols[col] = diag1[row+col] = diag2[row-col+n] = true;
                solve(row + 1);
                cols[col] = diag1[row+col] = diag2[row-col+n] = false;
            }
        }
    }
    solve(0);
    console.log(count);
    rl.close();
});
