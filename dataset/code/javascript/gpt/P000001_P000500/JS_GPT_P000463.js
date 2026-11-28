// Find Common Elements in Three Sorted Arrays
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [aN, bN, cN] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let b = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let c = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let i = 0;
let j = 0;
let k = 0;
let o = [];
while ((i < aN && j < bN && k < cN)) {
    if (a[i] === b[j] && b[j] === c[k]) {
        o.push(a[i]);
        i += 1;
        j += 1;
        k += 1;
    } else {
        let m = Math.min(a[i], b[j], c[k]);
        i += a[i] === m;
        j += b[j] === m;
        k += c[k] === m;
    }
}
console.log(...o);
