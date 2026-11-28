// Build Array With Stack Operations
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let m = parseInt(_stdin_next_line(), 10);
let target = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let n = parseInt(_stdin_next_line(), 10);
let out = [];
let i = 0;
for (const x of Array.from({length: ((n + 1)) - (1)}, (_, i) => (1) + i)) {
    out.push("Push");
    if ((i < (target.length !== undefined ? target.length : target.size) && target[i] === x)) {
        i += 1;
    } else {
        out.push("Pop");
    }
    if (i === (target.length !== undefined ? target.length : target.size)) {
        break;
    }
}
console.log(...out);
