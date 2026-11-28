// Chessboard Game
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function chessboard_game(x, y) {
    x = ((x - 1) % 4);
    y = ((y - 1) % 4);
    if (((x === 0 || x === 1) && (y === 0 || y === 1))) {
        return "Second";
    }
    return "First";
}
let t = parseInt(_stdin_next_line(), 10);
for (const _ of Array.from({length: t}, (_, i) => i)) {
    let [x, y] = _stdin_next_line().trim().split(/\s+/).map(Number);
    console.log(chessboard_game(x, y));
}
