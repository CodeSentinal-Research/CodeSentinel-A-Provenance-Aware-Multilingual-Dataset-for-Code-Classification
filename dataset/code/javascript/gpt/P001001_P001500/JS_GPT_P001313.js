// P001313 - Sudoku Solver
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 81) return;
    const board = [];
    let ptr = 0;
    for (let i = 0; i < 9; i++) {
        const row = [];
        for (let j = 0; j < 9; j++) row.push(parseInt(input[ptr++], 10));
        board.push(row);
    }
    function isValid(r, c, val) {
        for (let i = 0; i < 9; i++) {
            if (board[r][i] === val || board[i][c] === val) return false;
            const br = 3 * Math.floor(r / 3) + Math.floor(i / 3);
            const bc = 3 * Math.floor(c / 3) + (i % 3);
            if (board[br][bc] === val) return false;
        }
        return true;
    }
    function solve() {
        for (let r = 0; r < 9; r++) {
            for (let c = 0; c < 9; c++) {
                if (board[r][c] === 0) {
                    for (let val = 1; val <= 9; val++) {
                        if (isValid(r, c, val)) {
                            board[r][c] = val;
                            if (solve()) return true;
                            board[r][c] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    solve();
    for (let i = 0; i < 9; i++) {
        console.log(board[i].join(" "));
    }
}

main();
