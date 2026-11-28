// Search in Rotated Sorted Array
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
let [l, r] = [0, (n - 1)];
while (l <= r) {
    let m = Math.floor((l + r) / 2);
    if (a[m] === t) {
        console.log(m);
        break;
    }
    if (a[l] <= a[m]) {
        if (a[l] <= t && t < a[m]) {
            r = (m - 1);
        } else {
            l = (m + 1);
        }
    } else {
        if (a[m] < t && t <= a[r]) {
            l = (m + 1);
        } else {
            r = (m - 1);
        }
    }
}
