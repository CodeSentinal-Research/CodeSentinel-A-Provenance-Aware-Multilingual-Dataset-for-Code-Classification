// Find Peak Element in 2D Matrix
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [r, c] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = [...Array.from({length: r}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
let [lo, hi] = [0, (c - 1)];
while (lo <= hi) {
    let m = Math.floor((lo + hi) / 2);
    let i = Math.max(...Array.from({length: r}, (_, i) => i));
    let left = (m ? a[i][(m - 1)] : -(Math.pow(10, 18)));
    let right = ((m + 1) < c ? a[i][(m + 1)] : -(Math.pow(10, 18)));
    if ((a[i][m] >= left && a[i][m] >= right)) {
        console.log(a[i][m]);
        break;
    }
    if (left > a[i][m]) {
        hi = (m - 1);
    } else {
        lo = (m + 1);
    }
}
