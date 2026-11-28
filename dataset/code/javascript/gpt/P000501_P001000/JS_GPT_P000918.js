// Count Circular Arrangements
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function circular_arrangements(n) {
    if (n <= 1) {
        return 1;
    }
    let ans = 1;
    for (const i of Array.from({length: (n) - (1)}, (_, i) => (1) + i)) {
        ans *= i;
    }
    return ans;
}
let n = parseInt(_stdin_next_line(), 10);
console.log(circular_arrangements(n));
