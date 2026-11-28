// Extended Euclidean Algorithm
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
    let x = y1;
    let y = (x1 - (Math.floor(a / b) * y1));
    return [g, x, y];
}
let [a, b] = _stdin_next_line().trim().split(/\s+/).map(Number);
let [g, x, y] = ext_gcd(a, b);
console.log(`${g} ${x} ${y}`);
