// Binary Search on Answer for Aggressive Cows
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [n, c] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = [..._stdin_next_line().trim().split(/\s+/).map(Number)].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
let [lo, hi] = [0, (a[-(1)] - a[0])];
function ok(d) {
    let used = 1;
    let last = a[0];
    for (const x of a.slice(1)) {
        if ((x - last) >= d) {
            used += 1;
            last = x;
        }
    }
    return used >= c;
}
while (lo < hi) {
    let m = Math.floor(((lo + hi) + 1) / 2);
    if (ok(m)) {
        lo = m;
    } else {
        hi = (m - 1);
    }
}
console.log(lo);
