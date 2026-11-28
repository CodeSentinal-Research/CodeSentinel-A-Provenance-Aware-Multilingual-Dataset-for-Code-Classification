// Fast Modular Exponentiation
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
    base = (base % mod);
    while (exp > 0) {
        if ((exp % 2) === 1) {
            res = ((res * base) % mod);
        }
        base = ((base * base) % mod);
        exp = Math.floor(exp / (2));
    }
    return res;
}
let [base, exp, mod] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(mod_pow(base, exp, mod));
