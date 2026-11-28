// Median of Two Sorted Arrays
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    findMedianSortedArrays(nums1, nums2) {
        if ((nums1.length !== undefined ? nums1.length : nums1.size) > (nums2.length !== undefined ? nums2.length : nums2.size)) {
            let [nums1, nums2] = [nums2, nums1];
        }
        let [m, n] = [(nums1.length !== undefined ? nums1.length : nums1.size), (nums2.length !== undefined ? nums2.length : nums2.size)];
        let [left, right] = [0, m];
        while (left <= right) {
            let i = Math.floor((left + right) / 2);
            let j = (Math.floor(((m + n) + 1) / 2) - i);
            let max_left1 = (i === 0 ? parseFloat("-inf") : nums1[(i - 1)]);
            let min_right1 = (i === m ? parseFloat("inf") : nums1[i]);
            let max_left2 = (j === 0 ? parseFloat("-inf") : nums2[(j - 1)]);
            let min_right2 = (j === n ? parseFloat("inf") : nums2[j]);
            if ((max_left1 <= min_right2 && max_left2 <= min_right1)) {
                if (((m + n) % 2) === 1) {
                    return parseFloat(Math.max(max_left1, max_left2));
                } else {
                    return ((Math.max(max_left1, max_left2) + Math.min(min_right1, min_right2)) / 2.0);
                }
            } else {
                if (max_left1 > min_right2) {
                    right = (i - 1);
                } else {
                    left = (i + 1);
                }
            }
        }
        return 0.0;
    }
}
