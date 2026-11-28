// Tribonacci Sequence
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    tribonacci(n) {
        if (n === 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        let [a, b, c] = [0, 1, 1];
        for (const _ of Array.from({length: ((n + 1)) - (3)}, (_, i) => (3) + i)) {
            [a, b, c] = [b, c, ((a + b) + c)];
        }
        return c;
    }
}
