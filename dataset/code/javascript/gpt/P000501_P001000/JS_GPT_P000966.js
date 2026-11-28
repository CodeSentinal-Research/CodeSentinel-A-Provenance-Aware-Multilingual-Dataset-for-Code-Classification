// Verify Chinese Remainder Solution
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function verify_crt(x, num, rem) {
    for (const [n, r] of zip(num, rem)) {
        if ((x % n) !== r) {
            return false;
        }
    }
    return true;
}
let x = parseInt(_stdin_next_line(), 10);
let k = parseInt(_stdin_next_line(), 10);
let num = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let rem = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log((verify_crt(x, num, rem) ? "YES" : "NO"));
