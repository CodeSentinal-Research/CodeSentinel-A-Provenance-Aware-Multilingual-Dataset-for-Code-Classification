// Trace of a Square Matrix
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function matrix_trace(mat) {
    return [...Array.from({length: (mat.length !== undefined ? mat.length : mat.size)}, (_, i) => i)].map(i => mat[i][i]).reduce((a, b) => a + b, 0);
}
let n = parseInt(_stdin_next_line(), 10);
let mat = [...Array.from({length: n}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
console.log(matrix_trace(mat));
