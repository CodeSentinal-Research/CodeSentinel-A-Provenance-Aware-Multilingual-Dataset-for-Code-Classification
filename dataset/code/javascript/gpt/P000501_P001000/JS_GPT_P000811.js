// Guess Number Higher or Lower
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    guessNumber(n) {
        let [low, high] = [1, n];
        while (low <= high) {
            let mid = (low + Math.floor((high - low) / 2));
            let res = guess(mid);
            if (res === 0) {
                return mid;
            } else {
                if (res < 0) {
                    high = (mid - 1);
                } else {
                    low = (mid + 1);
                }
            }
        }
        return low;
    }
}
