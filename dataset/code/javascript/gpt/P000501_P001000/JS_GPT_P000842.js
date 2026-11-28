// Maximum Value at a Given Index in a Bounded Array
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    maxValue(n, index, maxSum) {
        function calc_sum(count, val) {
            if (val >= count) {
                return Math.floor(((((val + val) - count) + 1) * count) / 2);
            } else {
                return (Math.floor(((val + 1) * val) / 2) + (count - val));
            }
        }
        let left_count = index;
        let right_count = ((n - 1) - index);
        let [low, high] = [1, maxSum];
        let ans = 1;
        while (low <= high) {
            let mid = (low + Math.floor((high - low) / 2));
            let total = ((mid + calc_sum(left_count, (mid - 1))) + calc_sum(right_count, (mid - 1)));
            if (total <= maxSum) {
                ans = mid;
                low = (mid + 1);
            } else {
                high = (mid - 1);
            }
        }
        return ans;
    }
}
