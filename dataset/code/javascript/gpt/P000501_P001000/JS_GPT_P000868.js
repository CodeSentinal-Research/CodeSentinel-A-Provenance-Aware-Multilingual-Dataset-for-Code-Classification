// Total Hamming Distance
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    totalHammingDistance(nums) {
        let total = 0;
        let n = (nums.length !== undefined ? nums.length : nums.size);
        for (const i of Array.from({length: 32}, (_, i) => i)) {
            let ones = [...nums].map(x => ((x >> i) & 1)).reduce((a, b) => a + b, 0);
            total += (ones * (n - ones));
        }
        return total;
    }
}
