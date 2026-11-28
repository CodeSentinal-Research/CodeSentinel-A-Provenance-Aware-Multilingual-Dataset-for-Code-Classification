const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function solve(row, cols, diag1, diag2, board) {
        if (row === n) {
            res.push(board.map(r => r.join('')).join("\n"));
            return;
        }
        for (let col = 0; col < n; col++) {
            if (!cols[col] && !diag1[row - col + n] && !diag2[row + col]) {
                cols[col] = true;
                diag1[row - col + n] = true;
                diag2[row + col] = true;
                board[row][col] = 'Q';
                solve(row + 1, cols, diag1, diag2, board);
                board[row][col] = '.';
                cols[col] = false;
                diag1[row - col + n] = false;
                diag2[row + col] = false;
            }
        }
    }
    let board = Array(n).fill(0).map(() => Array(n).fill('.'));
    solve(0, {}, {}, {}, board);
    console.log(res.join("\n\n"));
    rl.close();
});
