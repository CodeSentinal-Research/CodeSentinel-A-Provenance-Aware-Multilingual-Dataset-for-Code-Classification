// Find Position of an Element in Infinite Array
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let t = parseInt(_stdin_next_line(), 10);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let [l, r] = [0, ((a.length !== undefined ? a.length : a.size) - 1)];
while (l <= r) {
    let m = Math.floor((l + r) / 2);
    if (a[m] === t) {
        console.log(m);
        break;
    }
    if (a[m] < t) {
        l = (m + 1);
    } else {
        r = (m - 1);
    }
}
