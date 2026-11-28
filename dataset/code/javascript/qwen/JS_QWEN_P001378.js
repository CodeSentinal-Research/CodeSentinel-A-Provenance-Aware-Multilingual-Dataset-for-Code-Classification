const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let board = Array(n).fill('.').map(()=>Array(n).fill('.'));
    let cols = new Array(n).fill(false);
    let diag1 = new Array(2*n).fill(false);
    let diag2 = new Array(2*n).fill(false);
    let res = [];
    
    function solve(row) {
        if(row===n) {
            res.push(board.map(r=>r.join('')).join('\n'));
            return;
        }
        for(let col=0; col<n; col++) {
            if(!cols[col] && !diag1[row+col] && !diag2[row-col+n]) {
                cols[col] = diag1[row+col] = diag2[row-col+n] = true;
                board[row][col] = 'Q';
                solve(row+1);
                board[row][col] = '.';
                cols[col] = diag1[row+col] = diag2[row-col+n] = false;
            }
        }
    }
    solve(0);
    console.log(res.join("\n\n"));
    rl.close();
});
