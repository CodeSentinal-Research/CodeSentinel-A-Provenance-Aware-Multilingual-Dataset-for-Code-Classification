// Misère Nim
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function misere_nim_winner(piles) {
    let all_ones = [...piles].map(x => x === 1).every(Boolean);
    let xor_sum = 0;
    for (const x of piles) {
        xor_sum ^= x;
    }
    if (all_ones) {
        return (((piles.length !== undefined ? piles.length : piles.size) % 2) === 0 ? "First" : "Second");
    } else {
        return (xor_sum !== 0 ? "First" : "Second");
    }
}
let t = parseInt(_stdin_next_line(), 10);
for (const _ of Array.from({length: t}, (_, i) => i)) {
    let n = parseInt(_stdin_next_line(), 10);
    let piles = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
    console.log(misere_nim_winner(piles));
}
