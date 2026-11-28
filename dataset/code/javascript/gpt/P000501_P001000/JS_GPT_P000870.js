// Sum of Two Integers Without Arithmetic Operators
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    getSum(a, b) {
        let mask = 4294967295;
        let max_int = 2147483647;
        while (b !== 0) {
            let carry = (((a & b) << 1) & mask);
            let a = ((a ^ b) & mask);
            let b = carry;
        }
        return (a <= max_int ? a : ~((a ^ mask)));
    }
}
