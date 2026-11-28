// Minimize the Maximum Pair Difference
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    minimizeMax(nums, p) {
        if (p === 0) {
            return 0;
        }
        nums.sort();
        function can_form(diff) {
            let count = 0;
            let i = 0;
            while (i < ((nums.length !== undefined ? nums.length : nums.size) - 1)) {
                if ((nums[(i + 1)] - nums[i]) <= diff) {
                    count += 1;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            return count >= p;
        }
        let [left, right] = [0, (nums[-(1)] - nums[0])];
        let ans = right;
        while (left <= right) {
            let mid = (left + Math.floor((right - left) / 2));
            if (can_form(mid)) {
                ans = mid;
                right = (mid - 1);
            } else {
                left = (mid + 1);
            }
        }
        return ans;
    }
}
