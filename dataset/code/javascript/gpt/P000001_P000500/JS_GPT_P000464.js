// Find Closest Element
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
let i = bisect.bisect_left(a, t);
if (i === 0) {
    let ans = a[0];
} else {
    if (i === n) {
        ans = a[-(1)];
    } else {
        ans = (Math.abs((a[i] - t)) < Math.abs((a[(i - 1)] - t)) ? a[i] : a[(i - 1)]);
    }
}
console.log(ans);
