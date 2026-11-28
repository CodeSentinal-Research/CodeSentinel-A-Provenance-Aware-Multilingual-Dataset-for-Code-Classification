// Count Numbers with Unique Digits
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    countNumbersWithUniqueDigits(n) {
        if (n === 0) {
            return 1;
        }
        let ans = 10;
        let unique_digits = 9;
        let available = 9;
        for (const i of Array.from({length: (Math.min((n + 1), 11)) - (2)}, (_, i) => (2) + i)) {
            unique_digits *= available;
            ans += unique_digits;
            available -= 1;
        }
        return ans;
    }
}
