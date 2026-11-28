// Predict the Winner
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    predictTheWinner(nums) {
        let n = (nums.length !== undefined ? nums.length : nums.size);
        let dp = Array.from(nums);
        for (const i of _py_range((n - 2), -(1), -(1))) {
            for (const j of Array.from({length: (n) - ((i + 1))}, (_, i) => ((i + 1)) + i)) {
                dp[j] = Math.max((nums[i] - dp[j]), (nums[j] - dp[(j - 1)]));
            }
        }
        return dp[(n - 1)] >= 0;
    }
}
