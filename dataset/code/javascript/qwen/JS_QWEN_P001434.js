const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let moves = [];
        for (let i = 1; i <= n; i++) moves.push(lines[i].split(/\s+/).map(Number));
        
        let board = Array(3).fill(0).map(()=>Array(3).fill(0));
        let winner = 0;
        for (let [r, c] of moves) {
            let player = moves.indexOf([r,c]) % 2 === 0 ? 1 : 2;
            board[r][c] = player;
            
            // Check row, col, diag
            if (board[r][0]===player && board[r][1]===player && board[r][2]===player) winner = player;
            if (board[0][c]===player && board[1][c]===player && board[2][c]===player) winner = player;
            if (r===c && board[0][0]===player && board[1][1]===player && board[2][2]===player) winner = player;
            if (r+c===2 && board[0][2]===player && board[1][1]===player && board[2][0]===player) winner = player;
        }
        
        if (winner) console.log(winner === 1 ? "A" : "B");
        else if (n < 9) console.log("Pending");
        else console.log("Draw");
        rl.close();
    }
});
