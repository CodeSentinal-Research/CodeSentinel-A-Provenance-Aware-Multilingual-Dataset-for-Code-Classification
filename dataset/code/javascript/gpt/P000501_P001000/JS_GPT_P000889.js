// Prime Number Check
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_prime(n) {
    if (n < 2) {
        return false;
    }
    for (const i of Array.from({length: ((parseInt(Math.pow(n, 0.5), 10) + 1)) - (2)}, (_, i) => (2) + i)) {
        if ((n % i) === 0) {
            return false;
        }
    }
    return true;
}
let n = parseInt(_stdin_next_line(), 10);
console.log((is_prime(n) ? "YES" : "NO"));
