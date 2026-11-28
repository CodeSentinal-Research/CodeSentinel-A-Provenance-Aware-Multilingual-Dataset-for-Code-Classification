// Distinct Prime Factors
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function distinct_prime_factors(n) {
    let factors = [];
    let d = 2;
    while ((d * d) <= n) {
        if ((n % d) === 0) {
            factors.push(d);
            while ((n % d) === 0) {
                n = Math.floor(n / (d));
            }
        }
        d += 1;
    }
    if (n > 1) {
        factors.push(n);
    }
    return factors;
}
let n = parseInt(_stdin_next_line(), 10);
console.log(distinct_prime_factors(n).map(String).join(" "));
