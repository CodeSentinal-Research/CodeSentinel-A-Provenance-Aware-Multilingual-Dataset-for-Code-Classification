// Rotate Matrix by 90 Degrees Clockwise
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    rotate(matrix) {
        let n = (matrix.length !== undefined ? matrix.length : matrix.size);
        for (const i of Array.from({length: n}, (_, i) => i)) {
            for (const j of Array.from({length: (n) - (i)}, (_, i) => (i) + i)) {
                [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
            }
        }
        for (const i of Array.from({length: n}, (_, i) => i)) {
            matrix[i].reverse();
        }
    }
}
