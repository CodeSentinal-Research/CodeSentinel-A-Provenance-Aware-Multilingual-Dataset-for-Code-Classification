// XOR Queries of a Subarray
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    xorQueries(arr, queries) {
        let prefix = ([0] * ((arr.length !== undefined ? arr.length : arr.size) + 1));
        for (const i of Array.from({length: (arr.length !== undefined ? arr.length : arr.size)}, (_, i) => i)) {
            prefix[(i + 1)] = (prefix[i] ^ arr[i]);
        }
        return [...queries].map(([l, r]) => (prefix[(r + 1)] ^ prefix[l]));
    }
}
