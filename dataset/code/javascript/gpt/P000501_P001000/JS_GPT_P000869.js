// Divide Two Integers Without Division
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    divide(dividend, divisor) {
        if ((dividend === -(2147483648) && divisor === -(1))) {
            return 2147483647;
        }
        let sign = ((dividend < 0 ^ divisor < 0) ? -(1) : 1);
        let [dvd, dvs] = [Math.abs(dividend), Math.abs(divisor)];
        let ans = 0;
        while (dvd >= dvs) {
            let temp = dvs;
            let m = 1;
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return (sign * ans);
    }
}
