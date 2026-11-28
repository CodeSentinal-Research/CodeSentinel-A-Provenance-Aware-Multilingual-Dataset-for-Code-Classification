// Binomial Coefficient Modulo Prime
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function mod_pow(base, exp, mod) {
    let res = 1;
    base %= mod;
    while (exp > 0) {
        if ((exp % 2) === 1) {
            res = ((res * base) % mod);
        }
        base = ((base * base) % mod);
        exp = Math.floor(exp / (2));
    }
    return res;
}
function nCr_mod(n, r, p) {
    if ((r < 0 || r > n)) {
        return 0;
    }
    let num = 1;
    let den = 1;
    for (const i of Array.from({length: r}, (_, i) => i)) {
        num = ((num * (n - i)) % p);
        den = ((den * (i + 1)) % p);
    }
    return ((num * mod_pow(den, (p - 2), p)) % p);
}
let [n, r, p] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(nCr_mod(n, r, p));
