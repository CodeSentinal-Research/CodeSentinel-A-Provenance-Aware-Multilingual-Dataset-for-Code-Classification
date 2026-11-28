// Find First and Last Position of Element in Sorted Array
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    searchRange(nums, target) {
        function find_bound(is_first) {
            let [left, right] = [0, ((nums.length !== undefined ? nums.length : nums.size) - 1)];
            let ans = -(1);
            while (left <= right) {
                let mid = (left + Math.floor((right - left) / 2));
                if (nums[mid] === target) {
                    ans = mid;
                    if (is_first) {
                        right = (mid - 1);
                    } else {
                        left = (mid + 1);
                    }
                } else {
                    if (nums[mid] < target) {
                        left = (mid + 1);
                    } else {
                        right = (mid - 1);
                    }
                }
            }
            return ans;
        }
        return [find_bound(true), find_bound(false)];
    }
}
