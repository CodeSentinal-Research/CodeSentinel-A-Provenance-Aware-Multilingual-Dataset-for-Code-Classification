// Maximum Candies Allocated to K Children
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    maximumCandies(candies, k) {
        if (candies.reduce((a, b) => a + b, 0) < k) {
            return 0;
        }
        let [left, right] = [1, Math.max(...candies)];
        let ans = 0;
        while (left <= right) {
            let mid = (left + Math.floor((right - left) / 2));
            let children = [...candies].map(c => Math.floor(c / mid)).reduce((a, b) => a + b, 0);
            if (children >= k) {
                ans = mid;
                left = (mid + 1);
            } else {
                right = (mid - 1);
            }
        }
        return ans;
    }
}
