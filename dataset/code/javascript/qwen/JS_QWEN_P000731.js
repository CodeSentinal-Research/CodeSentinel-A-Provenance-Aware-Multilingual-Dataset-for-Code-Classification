const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let count = 0;
    function solve(row, cols, diag1, diag2) {
        if (row === n) {
            count++;
            return;
        }
        for (let col = 0; col < n; col++) {
            if (!cols[col] && !diag1[row - col + n] && !diag2[row + col]) {
                cols[col] = true;
                diag1[row - col + n] = true;
                diag2[row + col] = true;
                solve(row + 1, cols, diag1, diag2);
                cols[col] = false;
                diag1[row - col + n] = false;
                diag2[row + col] = false;
            }
        }
    }
    solve(0, {}, {}, {});
    console.log(count);
    rl.close();
});
