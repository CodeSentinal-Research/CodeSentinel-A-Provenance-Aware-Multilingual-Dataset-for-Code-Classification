// Minimum Positive Bézout Solution
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
function min_positive_bezout(a, b) {
    let [g, x, y] = ext_gcd(a, b);
    let step_x = Math.floor(b / g);
    let step_y = Math.floor(a / g);
    x = (((x % step_x) + step_x) % step_x);
    if (x === 0) {
        x += step_x;
    }
    y = Math.floor((g - (a * x)) / b);
    return [x, y];
}
let [a, b] = _stdin_next_line().trim().split(/\s+/).map(Number);
let [x, y] = min_positive_bezout(a, b);
console.log(`${x} ${y}`);
