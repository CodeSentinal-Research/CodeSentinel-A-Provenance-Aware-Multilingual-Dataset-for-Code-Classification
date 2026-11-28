// Sparse Matrix Multiplication
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    multiply(mat1, mat2) {
        let [r1, c1] = [(mat1.length !== undefined ? mat1.length : mat1.size), (mat1[0].length !== undefined ? mat1[0].length : mat1[0].size)];
        let c2 = (mat2[0].length !== undefined ? mat2[0].length : mat2[0].size);
        let res = [...Array.from({length: r1}, (_, i) => i)].map(_ => ([0] * c2));
        for (const i of Array.from({length: r1}, (_, i) => i)) {
            for (const k of Array.from({length: c1}, (_, i) => i)) {
                if (mat1[i][k] !== 0) {
                    for (const j of Array.from({length: c2}, (_, i) => i)) {
                        if (mat2[k][j] !== 0) {
                            res[i][j] += (mat1[i][k] * mat2[k][j]);
                        }
                    }
                }
            }
        }
        return res;
    }
}
