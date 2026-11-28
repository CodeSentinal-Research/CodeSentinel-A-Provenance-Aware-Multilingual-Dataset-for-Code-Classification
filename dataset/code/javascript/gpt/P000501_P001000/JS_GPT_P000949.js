// Euler Totient Function
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function phi(n) {
    let result = n;
    let p = 2;
    while ((p * p) <= n) {
        if ((n % p) === 0) {
            while ((n % p) === 0) {
                n = Math.floor(n / (p));
            }
            result -= Math.floor(result / p);
        }
        p += 1;
    }
    if (n > 1) {
        result -= Math.floor(result / n);
    }
    return result;
}
let n = parseInt(_stdin_next_line(), 10);
console.log(phi(n));
