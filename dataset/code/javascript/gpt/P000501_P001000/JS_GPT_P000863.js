// Single Number III
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    singleNumber(nums) {
        let xor_all = 0;
        for (const x of nums) {
            xor_all ^= x;
        }
        let diff = (xor_all & -(xor_all));
        let [a, b] = [0, 0];
        for (const x of nums) {
            if ((x & diff)) {
                a ^= x;
            } else {
                b ^= x;
            }
        }
        return [a, b];
    }
}
