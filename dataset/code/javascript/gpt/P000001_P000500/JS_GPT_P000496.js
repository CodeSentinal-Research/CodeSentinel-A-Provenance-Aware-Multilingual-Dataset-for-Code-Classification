// Sum of Subarray Minimums
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let MOD = (Math.pow(10, 9) + 7);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let n = (a.length !== undefined ? a.length : a.size);
let left = ([0] * n);
let right = ([0] * n);
let st = [];
for (const [i, x] of [...a].map((v, i) => [i, v])) {
    while ((st && a[st[-(1)]] > x)) {
        st.pop();
    }
    left[i] = (st ? (i - st[-(1)]) : (i + 1));
    st.push(i);
}
st = [];
for (const i of _py_range((n - 1), -(1), -(1))) {
    while ((st && a[st[-(1)]] >= a[i])) {
        st.pop();
    }
    right[i] = (st ? (st[-(1)] - i) : (n - i));
    st.push(i);
}
console.log(([...Array.from({length: n}, (_, i) => i)].map(i => ((a[i] * left[i]) * right[i])).reduce((a, b) => a + b, 0) % MOD));
