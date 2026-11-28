// Find Missing Element in AP
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let n = parseInt(_stdin_next_line(), 10);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let d = Math.floor((a[-(1)] - a[0]) / n);
for (const i of Array.from({length: ((a.length !== undefined ? a.length : a.size) - 1)}, (_, i) => i)) {
    if ((a[(i + 1)] - a[i]) !== d) {
        console.log((a[i] + d));
        break;
    }
}
