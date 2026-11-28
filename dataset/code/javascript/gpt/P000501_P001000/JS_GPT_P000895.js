// Least Common Multiple of Two Numbers
const fs = require("fs");
function _gcd(a, b) { while (b) { [a, b] = [b, a % b]; } return Math.abs(a); }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gcd(a, b) {
    while (b) {
        [a, b] = [b, (a % b)];
    }
    return a;
}
function lcm(a, b) {
    if ((a === 0 || b === 0)) {
        return 0;
    }
    return Math.floor((a * b) / _gcd(a, b));
}
let [a, b] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(lcm(a, b));
