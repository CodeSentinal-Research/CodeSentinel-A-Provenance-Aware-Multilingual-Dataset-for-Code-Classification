// Valid Perfect Square using Binary Search
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let n = parseInt(_stdin_next_line(), 10);
let [l, r] = [1, n];
while (l <= r) {
    let m = Math.floor((l + r) / 2);
    if ((m * m) === n) {
        console.log("Yes");
        break;
    }
    if ((m * m) < n) {
        l = (m + 1);
    } else {
        r = (m - 1);
    }
}
