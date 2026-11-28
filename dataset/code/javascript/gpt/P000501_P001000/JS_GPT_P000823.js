// K-th Missing Positive Number
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    findKthPositive(arr, k) {
        let [left, right] = [0, ((arr.length !== undefined ? arr.length : arr.size) - 1)];
        while (left <= right) {
            let mid = (left + Math.floor((right - left) / 2));
            let missing = (arr[mid] - (mid + 1));
            if (missing < k) {
                left = (mid + 1);
            } else {
                right = (mid - 1);
            }
        }
        return (left + k);
    }
}
