// Matrix Transpose
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    transpose(matrix) {
        let [r, c] = [(matrix.length !== undefined ? matrix.length : matrix.size), (matrix[0].length !== undefined ? matrix[0].length : matrix[0].size)];
        return [...Array.from({length: c}, (_, i) => i)].map(j => [...Array.from({length: r}, (_, i) => i)].map(i => matrix[i][j]));
    }
}
