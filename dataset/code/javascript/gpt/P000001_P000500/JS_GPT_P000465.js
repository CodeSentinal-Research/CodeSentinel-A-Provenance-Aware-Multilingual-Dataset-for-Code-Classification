// Find Pair with Given Difference
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [n, d] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let i = 0;
let j = 0;
let ok = false;
while ((i < n && j < n)) {
    if (i === j) {
        j += 1;
        continue;
    }
    let diff = (a[j] - a[i]);
    if (diff === d) {
        ok = true;
        break;
    }
    if (diff < d) {
        j += 1;
    } else {
        i += 1;
    }
}
console.log((ok ? "Yes" : "No"));
