// Check Divisibility by 9
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_divisible_by_9(s) {
    let total = [...s.trim()].filter(c => /^\d+$/.test(c)).map(c => parseInt(c, 10)).reduce((a, b) => a + b, 0);
    return (total % 9) === 0;
}
let s = _stdin_next_line().trim();
console.log((is_divisible_by_9(s) ? "YES" : "NO"));
