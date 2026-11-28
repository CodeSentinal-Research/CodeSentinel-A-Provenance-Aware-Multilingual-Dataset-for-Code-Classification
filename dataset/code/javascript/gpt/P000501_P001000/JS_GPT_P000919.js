// Count Even and Odd Digits
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    evenOddBit(n) {
        let even = 0;
        let odd = 0;
        let i = 0;
        while (n > 0) {
            if ((n & 1)) {
                if ((i % 2) === 0) {
                    even += 1;
                } else {
                    odd += 1;
                }
            }
            n >>= 1;
            i += 1;
        }
        return [even, odd];
    }
}
