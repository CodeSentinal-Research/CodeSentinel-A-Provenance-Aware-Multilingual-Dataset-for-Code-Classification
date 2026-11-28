// Search in 2D Matrix
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [r, c, t] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = [...Array.from({length: r}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
let [l, h] = [0, ((r * c) - 1)];
while (l <= h) {
    let m = Math.floor((l + h) / 2);
    let v = a[Math.floor(m / c)][(m % c)];
    if (v === t) {
        console.log("Found");
        break;
    }
    if (v < t) {
        l = (m + 1);
    } else {
        h = (m - 1);
    }
}
