// Search for a Range
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [n, t] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let lo = 0;
let hi = n;
while (lo < hi) {
    let m = Math.floor((lo + hi) / 2);
    if (a[m] < t) {
        lo = (m + 1);
    } else {
        hi = m;
    }
}
if ((lo === n || a[lo] !== t)) {
    console.log(-(1), -(1));
} else {
    let [l, r] = [lo, n];
    while (l < r) {
        m = Math.floor((l + r) / 2);
        if (a[m] <= t) {
            l = (m + 1);
        } else {
            r = m;
        }
    }
    console.log(lo, (l - 1));
}
