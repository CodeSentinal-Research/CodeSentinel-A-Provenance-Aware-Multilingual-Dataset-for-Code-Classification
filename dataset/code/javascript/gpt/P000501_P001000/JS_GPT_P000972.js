// Probability of Getting Exactly K Heads
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function prob_heads(n, k, p) {
    if ((k < 0 || k > n)) {
        return 0.0;
    }
    let ways = Math.comb(n, k);
    return ((ways * Math.pow(p, k)) * Math.pow((1.0 - p), (n - k)));
}
let [n, k] = _stdin_next_line().trim().split(/\s+/).map(Number);
let p = parseFloat(_stdin_next_line());
console.log(`${prob_heads(n, k, p)}`);
