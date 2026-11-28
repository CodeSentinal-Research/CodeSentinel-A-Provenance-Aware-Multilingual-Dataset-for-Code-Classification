const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 9) {
        let board = lines.map(l => l.split(''));
        function solve(board) {
            for (let r = 0; r < 9; r++) {
                for (let c = 0; c < 9; c++) {
                    if (board[r][c] === '.') {
                        for (let num = 1; num <= 9; num++) {
                            if (isValid(board, r, c, num.toString())) {
                                board[r][c] = num.toString();
                                if (solve(board)) return true;
                                board[r][c] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        function isValid(board, row, col, num) {
            for (let i = 0; i < 9; i++) {
                if (board[row][i] === num || board[i][col] === num) return false;
                let br = 3 * Math.floor(row / 3) + Math.floor(i / 3);
                let bc = 3 * Math.floor(col / 3) + i % 3;
                if (board[br][bc] === num) return false;
            }
            return true;
        }
        solve(board);
        board.forEach(row => console.log(row.join('')));
        rl.close();
    }
});
