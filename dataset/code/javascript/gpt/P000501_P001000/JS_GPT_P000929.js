// Matrix Addition
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function matrix_addition(a, b) {
    let [r, c] = [(a.length !== undefined ? a.length : a.size), (a[0].length !== undefined ? a[0].length : a[0].size)];
    return [...Array.from({length: r}, (_, i) => i)].map(i => [...Array.from({length: c}, (_, i) => i)].map(j => (a[i][j] + b[i][j])));
}
let [r, c] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = [...Array.from({length: r}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
let b = [...Array.from({length: r}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
let res = matrix_addition(a, b);
for (const row of res) {
    console.log(row.map(String).join(" "));
}
