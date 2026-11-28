// Allocate Minimum Number of Pages
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [n, m] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let [lo, hi] = [Math.max(...a), a.reduce((a, b) => a + b, 0)];
function ok(cap) {
    let students = 1;
    let cur = 0;
    for (const x of a) {
        if ((cur + x) > cap) {
            students += 1;
            cur = x;
        } else {
            cur += x;
        }
    }
    return students <= m;
}
while (lo < hi) {
    let mid = Math.floor((lo + hi) / 2);
    if (ok(mid)) {
        hi = mid;
    } else {
        lo = (mid + 1);
    }
}
console.log(lo);
