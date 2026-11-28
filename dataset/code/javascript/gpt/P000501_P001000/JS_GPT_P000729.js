// Sudoku Solver
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function solve_sudoku(board) {
    function is_valid(r, c, ch) {
        for (const i of Array.from({length: 9}, (_, i) => i)) {
            if ((board[r][i] === ch || board[i][c] === ch)) {
                return false;
            }
            if (board[((3 * Math.floor(r / 3)) + Math.floor(i / 3))][((3 * Math.floor(c / 3)) + (i % 3))] === ch) {
                return false;
            }
        }
        return true;
    }
    function backtrack() {
        for (const r of Array.from({length: 9}, (_, i) => i)) {
            for (const c of Array.from({length: 9}, (_, i) => i)) {
                if (board[r][c] === ".") {
                    for (const d of "123456789") {
                        if (is_valid(r, c, d)) {
                            board[r][c] = d;
                            if (backtrack()) {
                                return true;
                            }
                            board[r][c] = ".";
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    backtrack();
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let board = [...Array.from({length: 9}, (_, i) => i)].map(i => Array.from(tokens[i]));
        solve_sudoku(board);
        for (const row of board) {
            console.log(row.join(""));
        }
    }
}
main();
