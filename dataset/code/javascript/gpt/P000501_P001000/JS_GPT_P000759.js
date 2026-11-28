// Count Good Numbers
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let MOD = (Math.pow(10, 9) + 7);
function mod_pow(base, exp, mod) {
    if (exp === 0) {
        return 1;
    }
    let half = mod_pow(base, Math.floor(exp / 2), mod);
    let res = ((half * half) % mod);
    if ((exp % 2) !== 0) {
        res = ((res * base) % mod);
    }
    return res;
}
function count_good_numbers(n) {
    let even_pos = Math.floor((n + 1) / 2);
    let odd_pos = Math.floor(n / 2);
    return ((mod_pow(5, even_pos, MOD) * mod_pow(4, odd_pos, MOD)) % MOD);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        console.log(count_good_numbers(n));
    }
}
main();
