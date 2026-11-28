// Koko Eating Bananas
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [n, h] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let [lo, hi] = [1, Math.max(...a)];
while (lo < hi) {
    let m = Math.floor((lo + hi) / 2);
    let hours = [...a].map(x => Math.floor(((x + m) - 1) / m)).reduce((a, b) => a + b, 0);
    if (hours <= h) {
        hi = m;
    } else {
        lo = (m + 1);
    }
}
console.log(lo);
