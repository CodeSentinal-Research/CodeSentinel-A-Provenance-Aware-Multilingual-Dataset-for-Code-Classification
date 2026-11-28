// Chinese Remainder Theorem Solver
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function ext_gcd(a, b) {
    if (b === 0) {
        return [a, 1, 0];
    }
    let [g, x1, y1] = ext_gcd(b, (a % b));
    return [g, y1, (x1 - (Math.floor(a / b) * y1))];
}
function crt(num, rem) {
    let prod = 1;
    for (const n of num) {
        prod *= n;
    }
    let result = 0;
    for (const [n, r] of zip(num, rem)) {
        let pp = Math.floor(prod / n);
        let [_, inv, __2] = ext_gcd(pp, n);
        inv = (((inv % n) + n) % n);
        result = ((result + ((r * pp) * inv)) % prod);
    }
    return result;
}
let k = parseInt(_stdin_next_line(), 10);
let num = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let rem = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log(crt(num, rem));
