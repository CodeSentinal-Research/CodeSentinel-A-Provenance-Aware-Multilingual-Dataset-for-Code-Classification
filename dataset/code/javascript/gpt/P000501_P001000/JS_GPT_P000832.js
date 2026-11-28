// Split Array Largest Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    splitArray(nums, k) {
        function can_split(max_sum) {
            let pieces = 1;
            let curr_sum = 0;
            for (const x of nums) {
                if ((curr_sum + x) > max_sum) {
                    pieces += 1;
                    curr_sum = x;
                } else {
                    curr_sum += x;
                }
            }
            return pieces <= k;
        }
        let [left, right] = [Math.max(...nums), nums.reduce((a, b) => a + b, 0)];
        let ans = right;
        while (left <= right) {
            let mid = (left + Math.floor((right - left) / 2));
            if (can_split(mid)) {
                ans = mid;
                right = (mid - 1);
            } else {
                left = (mid + 1);
            }
        }
        return ans;
    }
}
