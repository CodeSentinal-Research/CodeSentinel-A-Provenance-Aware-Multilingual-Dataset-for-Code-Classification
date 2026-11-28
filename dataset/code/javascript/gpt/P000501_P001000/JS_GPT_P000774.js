// Recursive Word Search
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function word_search(board, word) {
    let [n, m] = [(board.length !== undefined ? board.length : board.size), (board[0].length !== undefined ? board[0].length : board[0].size)];
    function backtrack(r, c, idx) {
        if (idx === (word.length !== undefined ? word.length : word.size)) {
            return true;
        }
        if ((r < 0 || r >= n || c < 0 || c >= m || board[r][c] !== word[idx])) {
            return false;
        }
        let temp = board[r][c];
        board[r][c] = "#";
        let res = (backtrack((r + 1), c, (idx + 1)) || backtrack((r - 1), c, (idx + 1)) || backtrack(r, (c + 1), (idx + 1)) || backtrack(r, (c - 1), (idx + 1)));
        board[r][c] = temp;
        return res;
    }
    for (const i of Array.from({length: n}, (_, i) => i)) {
        for (const j of Array.from({length: m}, (_, i) => i)) {
            if (backtrack(i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let m = parseInt(tokens[1], 10);
        let board = [];
        let idx = 2;
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            board.push([...Array.from({length: m}, (_, i) => i)].map(j => tokens[(idx + j)]));
            idx += m;
        }
        let word = tokens[idx];
        console.log((word_search(board, word) ? "true" : "false"));
    }
}
main();
