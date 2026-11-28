// Main and Secondary Diagonal Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    diagonalSum(mat) {
        let n = (mat.length !== undefined ? mat.length : mat.size);
        let total = 0;
        for (const i of Array.from({length: n}, (_, i) => i)) {
            total += mat[i][i];
            if (i !== ((n - 1) - i)) {
                total += mat[i][((n - 1) - i)];
            }
        }
        return total;
    }
}
