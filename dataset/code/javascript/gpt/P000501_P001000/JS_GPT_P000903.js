// Largest Divisible Subset
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    largestDivisibleSubset(nums) {
        if (!(nums)) {
            return [];
        }
        nums.sort();
        let n = (nums.length !== undefined ? nums.length : nums.size);
        let dp = ([1] * n);
        let parent = ([-(1)] * n);
        let max_len = 1;
        let max_idx = 0;
        for (const i of Array.from({length: (n) - (1)}, (_, i) => (1) + i)) {
            for (const j of Array.from({length: i}, (_, i) => i)) {
                if (((nums[i] % nums[j]) === 0 && (dp[j] + 1) > dp[i])) {
                    dp[i] = (dp[j] + 1);
                    parent[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_idx = i;
            }
        }
        let res = [];
        let curr = max_idx;
        while (curr !== -(1)) {
            res.push(nums[curr]);
            curr = parent[curr];
        }
        return res.slice(0);
    }
}
