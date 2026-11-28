// Count Valid Handshakes
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_handshakes(n) {
    if ((n % 2) === 1) {
        return 0;
    }
    let k = Math.floor(n / 2);
    let ans = 1;
    for (const i of Array.from({length: k}, (_, i) => i)) {
        ans = Math.floor((ans * ((2 * k) - i)) / (i + 1));
    }
    return Math.floor(ans / (k + 1));
}
let n = parseInt(_stdin_next_line(), 10);
console.log(count_handshakes(n));
