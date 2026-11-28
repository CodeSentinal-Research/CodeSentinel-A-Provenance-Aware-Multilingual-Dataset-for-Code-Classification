// Armstrong Number
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_armstrong(n) {
    let digits = [...String(n)].map(d => parseInt(d, 10));
    let k = (digits.length !== undefined ? digits.length : digits.size);
    return [...digits].map(d => Math.pow(d, k)).reduce((a, b) => a + b, 0) === n;
}
let n = parseInt(_stdin_next_line(), 10);
console.log((is_armstrong(n) ? "YES" : "NO"));
