// Decode String
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let s = _stdin_next_line();
let counts = [];
let parts = [""];
let num = 0;
for (const ch of s) {
    if (/^\d+$/.test(ch)) {
        num = ((num * 10) + parseInt(ch, 10));
    } else {
        if (ch === "[") {
            counts.push(num);
            parts.push("");
            num = 0;
        } else {
            if (ch === "]") {
                parts[-(2)] += (parts.pop() * counts.pop());
            } else {
                parts[-(1)] += ch;
            }
        }
    }
}
console.log(parts[0]);
