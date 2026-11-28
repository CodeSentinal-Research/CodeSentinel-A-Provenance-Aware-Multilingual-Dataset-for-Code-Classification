// Reverse Bits
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    reverseBits(n) {
        let ans = 0;
        for (const _ of Array.from({length: 32}, (_, i) => i)) {
            ans = ((ans << 1) | (n & 1));
            n >>= 1;
        }
        return ans;
    }
}
