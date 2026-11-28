// Sum of Digits in a Range
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function sum_digits_up_to(n) {
    if (n <= 0) {
        return 0;
    }
    let s = String(n);
    let d = (s.length !== undefined ? s.length : s.size);
    if (d === 1) {
        return Math.floor((n * (n + 1)) / 2);
    }
    let first = parseInt(s[0], 10);
    let rem = (s.slice(1) ? parseInt(s.slice(1), 10) : 0);
    let p = Math.pow(10, (d - 1));
    let ans = (((first * 45) * (d - 1)) * Math.floor(p / 10));
    ans += (Math.floor((first * (first - 1)) / 2) * p);
    ans += (first * (rem + 1));
    ans += sum_digits_up_to(rem);
    return ans;
}
function sum_digits_range(l, r) {
    return (sum_digits_up_to(r) - sum_digits_up_to((l - 1)));
}
let [l, r] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(sum_digits_range(l, r));
