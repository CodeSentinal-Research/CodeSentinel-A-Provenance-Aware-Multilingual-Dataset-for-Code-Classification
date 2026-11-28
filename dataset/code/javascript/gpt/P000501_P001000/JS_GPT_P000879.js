// Reverse Integer
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    reverse(x) {
        let sign = (x < 0 ? -(1) : 1);
        let rev = (parseInt(String(Math.abs(x)).slice(0), 10) * sign);
        if ((rev < -(Math.pow(2, 31)) || rev > (Math.pow(2, 31) - 1))) {
            return 0;
        }
        return rev;
    }
}
