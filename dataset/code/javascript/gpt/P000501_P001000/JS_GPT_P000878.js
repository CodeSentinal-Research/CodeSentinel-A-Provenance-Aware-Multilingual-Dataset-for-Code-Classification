// Bitwise ORs of Subarrays
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    subarrayBitwiseORs(arr) {
        let res = new Set();
        let cur = new Set();
        for (const x of arr) {
            cur = (new Set([...cur].map(y => (x | y))) | new Set([x]));
            res |= cur;
        }
        return (res.length !== undefined ? res.length : res.size);
    }
}
