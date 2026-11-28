// Digit Frequency Counter
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function digit_frequency(n) {
    let freq = ([0] * 10);
    for (const d of String(Math.abs(n))) {
        freq[parseInt(d, 10)] += 1;
    }
    return freq;
}
let n = parseInt(_stdin_next_line(), 10);
console.log(digit_frequency(n).map(String).join(" "));
