// Generate Pascal's Triangle
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    generate(numRows) {
        let res = [];
        for (const i of Array.from({length: numRows}, (_, i) => i)) {
            let row = ([1] * (i + 1));
            for (const j of Array.from({length: (i) - (1)}, (_, i) => (1) + i)) {
                row[j] = (res[(i - 1)][(j - 1)] + res[(i - 1)][j]);
            }
            res.push(row);
        }
        return res;
    }
}
