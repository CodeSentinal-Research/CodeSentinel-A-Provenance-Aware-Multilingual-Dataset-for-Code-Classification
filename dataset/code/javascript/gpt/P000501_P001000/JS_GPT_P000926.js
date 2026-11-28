// Decimal to Octal and Hexadecimal
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function convert_bases(n) {
    return [oct(n).slice(2), hex(n).slice(2).toUpperCase()];
}
let n = parseInt(_stdin_next_line(), 10);
let [o, h] = convert_bases(n);
console.log(`${o} ${h}`);
