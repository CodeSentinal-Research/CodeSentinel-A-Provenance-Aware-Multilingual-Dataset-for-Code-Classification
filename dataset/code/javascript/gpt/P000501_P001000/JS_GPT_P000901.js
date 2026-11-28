// Check Divisibility by 11
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_divisible_by_11(s) {
    s = s.trim();
    let odd_sum = [..._py_range(0, (s.length !== undefined ? s.length : s.size), 2)].map(i => parseInt(s[i], 10)).reduce((a, b) => a + b, 0);
    let even_sum = [..._py_range(1, (s.length !== undefined ? s.length : s.size), 2)].map(i => parseInt(s[i], 10)).reduce((a, b) => a + b, 0);
    return (Math.abs((odd_sum - even_sum)) % 11) === 0;
}
let s = _stdin_next_line().trim();
console.log((is_divisible_by_11(s) ? "YES" : "NO"));
