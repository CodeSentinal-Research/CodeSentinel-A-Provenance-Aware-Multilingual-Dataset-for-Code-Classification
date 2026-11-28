// Knight's Tour
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function knights_tour(n, sr, sc) {
    let board = [...Array.from({length: n}, (_, i) => i)].map(_ => ([-(1)] * n));
    let moves = [[-(2), 1], [-(1), 2], [1, 2], [2, 1], [2, -(1)], [1, -(2)], [-(1), -(2)], [-(2), -(1)]];
    board[sr][sc] = 0;
    function backtrack(r, c, step) {
        if (step === (n * n)) {
            return true;
        }
        for (const [dr, dc] of moves) {
            let [nr, nc] = [(r + dr), (c + dc)];
            if ((0 <= nr && nr < n && 0 <= nc && nc < n && board[nr][nc] === -(1))) {
                board[nr][nc] = step;
                if (backtrack(nr, nc, (step + 1))) {
                    return true;
                }
                board[nr][nc] = -(1);
            }
        }
        return false;
    }
    if (backtrack(sr, sc, 1)) {
        for (const row of board) {
            console.log(...row);
        }
    } else {
        console.log(-(1));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let sr = parseInt(tokens[1], 10);
        let sc = parseInt(tokens[2], 10);
        knights_tour(n, sr, sc);
    }
}
main();
