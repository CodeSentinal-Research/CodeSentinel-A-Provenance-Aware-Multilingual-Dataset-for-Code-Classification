// Matrix Exponentiation
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let MOD = (Math.pow(10, 9) + 7);
function mat_mul(a, b) {
    let n = (a.length !== undefined ? a.length : a.size);
    let res = [...Array.from({length: n}, (_, i) => i)].map(_ => ([0] * n));
    for (const i of Array.from({length: n}, (_, i) => i)) {
        for (const k of Array.from({length: n}, (_, i) => i)) {
            for (const j of Array.from({length: n}, (_, i) => i)) {
                res[i][j] = ((res[i][j] + (a[i][k] * b[k][j])) % MOD);
            }
        }
    }
    return res;
}
function mat_pow(mat, p) {
    let n = (mat.length !== undefined ? mat.length : mat.size);
    let res = [...Array.from({length: n}, (_, i) => i)].map(i => [...Array.from({length: n}, (_, i) => i)].map(j => (i === j ? 1 : 0)));
    let base = mat;
    while (p > 0) {
        if ((p % 2) === 1) {
            res = mat_mul(res, base);
        }
        base = mat_mul(base, base);
        p = Math.floor(p / (2));
    }
    return res;
}
let [n, p] = _stdin_next_line().trim().split(/\s+/).map(Number);
let mat = [...Array.from({length: n}, (_, i) => i)].map(_ => Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)));
let ans = mat_pow(mat, p);
for (const row of ans) {
    console.log(row.map(String).join(" "));
}
