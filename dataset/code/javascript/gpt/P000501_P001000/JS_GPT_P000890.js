// Count Prime Numbers up to N
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    countPrimes(n) {
        if (n < 2) {
            return 0;
        }
        let is_prime = ([true] * n);
        is_prime[0] = false;
        is_prime[1] = false;
        for (const p of Array.from({length: ((parseInt(Math.pow(n, 0.5), 10) + 1)) - (2)}, (_, i) => (2) + i)) {
            if (is_prime[p]) {
                for (const i of _py_range((p * p), n, p)) {
                    is_prime[i] = false;
                }
            }
        }
        return is_prime.reduce((a, b) => a + b, 0);
    }
}
