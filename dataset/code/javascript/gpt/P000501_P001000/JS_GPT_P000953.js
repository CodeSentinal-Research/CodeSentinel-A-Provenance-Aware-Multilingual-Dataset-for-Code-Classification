// Euler's Theorem Evaluation
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function phi(n) {
    let res = n;
    let p = 2;
    while ((p * p) <= n) {
        if ((n % p) === 0) {
            while ((n % p) === 0) {
                n = Math.floor(n / (p));
            }
            res -= Math.floor(res / p);
        }
        p += 1;
    }
    if (n > 1) {
        res -= Math.floor(res / n);
    }
    return res;
}
function euler_pow(a, b, m) {
    let p = phi(m);
    let exp = (b % p);
    return pow(a, exp, m);
}
let [a, b, m] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(euler_pow(a, b, m));
