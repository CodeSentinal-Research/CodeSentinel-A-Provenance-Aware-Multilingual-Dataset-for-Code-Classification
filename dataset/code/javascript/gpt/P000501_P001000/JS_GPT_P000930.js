// Matrix Multiplication
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function matrix_multiplication(a, b) {
    let [r1, c1] = [(a.length !== undefined ? a.length : a.size), (a[0].length !== undefined ? a[0].length : a[0].size)];
    let [r2, c2] = [(b.length !== undefined ? b.length : b.size), (b[0].length !== undefined ? b[0].length : b[0].size)];
    let res = [...Array.from({length: r1}, (_, i) => i)].map(_ => ([0] * c2));
    for (const i of Array.from({length: r1}, (_, i) => i)) {
        for (const k of Array.from({length: c1}, (_, i) => i)) {
            for (const j of Array.from({length: c2}, (_, i) => i)) {
                res[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    return res;
}
let [r1, c1] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = [...Array.from({length: r1}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
let [r2, c2] = _stdin_next_line().trim().split(/\s+/).map(Number);
let b = [...Array.from({length: r2}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
let res = matrix_multiplication(a, b);
for (const row of res) {
    console.log(row.map(String).join(" "));
}
