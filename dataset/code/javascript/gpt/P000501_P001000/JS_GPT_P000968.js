// Merge Two Congruence Equations
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
function merge_congruences(r1, m1, r2, m2) {
    let [g, p, q] = ext_gcd(m1, m2);
    if (((r2 - r1) % g) !== 0) {
        return [-(1), -(1)];
    }
    let mod = Math.floor((m1 * m2) / g);
    let step = Math.floor((r2 - r1) / g);
    let k = ((p * step) % Math.floor(m2 / g));
    let ans = ((r1 + (k * m1)) % mod);
    return [(((ans % mod) + mod) % mod), mod];
}
let [r1, m1, r2, m2] = _stdin_next_line().trim().split(/\s+/).map(Number);
let [r, m] = merge_congruences(r1, m1, r2, m2);
if (r === -(1)) {
    console.log("-1");
} else {
    console.log(`${r} ${m}`);
}
