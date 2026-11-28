// Check Identity Matrix
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_identity_matrix(mat) {
    let n = (mat.length !== undefined ? mat.length : mat.size);
    for (const i of Array.from({length: n}, (_, i) => i)) {
        for (const j of Array.from({length: n}, (_, i) => i)) {
            let expected = (i === j ? 1 : 0);
            if (mat[i][j] !== expected) {
                return false;
            }
        }
    }
    return true;
}
let n = parseInt(_stdin_next_line(), 10);
let mat = [...Array.from({length: n}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
console.log((is_identity_matrix(mat) ? "YES" : "NO"));
