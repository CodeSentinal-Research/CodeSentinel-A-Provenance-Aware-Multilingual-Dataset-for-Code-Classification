// CRT with Non-Coprime Moduli
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
function crt_non_coprime(mods, rems) {
    let [a1, m1] = [rems[0], mods[0]];
    for (const i of Array.from({length: ((mods.length !== undefined ? mods.length : mods.size)) - (1)}, (_, i) => (1) + i)) {
        let [a2, m2] = [rems[i], mods[i]];
        let [g, p, q] = ext_gcd(m1, m2);
        if (((a2 - a1) % g) !== 0) {
            return -(1);
        }
        let mod = Math.floor((m1 * m2) / g);
        let step = Math.floor((a2 - a1) / g);
        let k = ((p * step) % Math.floor(m2 / g));
        a1 = ((a1 + (k * m1)) % mod);
        m1 = mod;
    }
    return (((a1 % m1) + m1) % m1);
}
let k = parseInt(_stdin_next_line(), 10);
let mods = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let rems = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log(crt_non_coprime(mods, rems));
