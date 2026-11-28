// Find K Closest Elements
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    findClosestElements(arr, k, x) {
        let [left, right] = [0, ((arr.length !== undefined ? arr.length : arr.size) - k)];
        while (left < right) {
            let mid = (left + Math.floor((right - left) / 2));
            if ((x - arr[mid]) > (arr[(mid + k)] - x)) {
                left = (mid + 1);
            } else {
                right = mid;
            }
        }
        return arr.slice(left, (left + k));
    }
}
